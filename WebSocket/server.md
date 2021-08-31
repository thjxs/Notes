# node server

创建一个 *https* 服务，用到两个证书文件 (key, cert)。 不处理任何 *http* 请求
监听一个端口，用于 *WebSocketServer* 创建

```js
"use strict";

var https = require('https');
var fs = require('fs');
var WebSocketServer = require('websocket').server;

var connectionArray = [];
var nextID = Date.now();
var appendToMakeUnique = 1;
var protocol = 'ws';

var httpsOptions = {
    key: fs.readFileSync('/path/to/name.key'),
    cert: fs.readFileSync('/path/to/name.crt')
};

var httpsServer = https.createServer(httpsOptions, function(request, response) {
    console.log((new Date()) + "Received request for " + request.url);
    response.writeHead(404);
    response.end();
});

httpsServer.listen(6502, function() {
    console.log((new Date()) + " Server is listening on port 6502");
});

var wsServer = new WebSocketServer({
    httpServer: httpsServer,
    autoAcceptConnections: false
});

function originIsAllowed(origin) {
    return true;
}

function isUsernameUnique(name) {
    var isUnique = true;
    var i;
    for (i = 0; i < connectionArray.length; i+=1) {
        if (connectionArray[i].username === name) {
            isUnique = false;
            break;
        }
    }
    return isUnique;
}

function getConnectionForID(id) {
    var connect = null;
    var i;
    for (i = 0; i < connectionArray.length; i+=1) {
        if (connectionArray[i].clientID === id) {
            connect = connectionArray[i];
            break;
        }
    }

    return connect;
}

function makeUserListMessage() {
    var userListMsg = {
        type: 'userlist',
        users: []
    };
    var i;

    for (i = 0; i < connectionArray.length; i++) {
        userListMsg.users.push(connectionArray[i].username);
    }

    return userListMsg;
}

function sendUserListToAll() {
    var userListMsg = makeUserListMessage();
    var userListMsgStr = JSON.stringify(userListMsg);
    var i;

    for (i = 0; i < connectionArray.length; i+=1) {
        connectionArray[i].sendUTF(userListMsgStr);
    }
}

wsServer.on('request', function(request) {
    if (!originIsAllowed(request.origin)) {
        request.reject();
        return;
    }

    var connection = request.accept(protocol, request.origin);
    connectionArray.push(connection);

    connection.clientID = nextID;
    nextID+=1;

    var msg = {
        type: 'id',
        id: connection.clientID
    };
    connection.sendUTF(JSON.stringify(msg));

    connection.on('message', function(message) {
        if (message.type === 'utf8') {
            var sendToClients = true;
            msg = JSON.parse(message.utf8Data);
            var connect = getConnectionForID(msg.id);

            switch(msg.type) {
                case 'message':
                    msg.name = connect.username;
                    msg.text = msg.text.replace(/(<([^>]+)>)/ig, '');
                    break;
                case 'username':
                    var nameChanged = false;
                    var origName = msg.name;

                    while (!isUsernameUnique(msg.name)) {
                        msg.name = origName + appendToMakeUnique;
                        appendToMakeUnique += 1;
                        nameChanged = true;
                    }

                    if (nameChanged) {
                        var changeMsg = {
                            id: msg.id,
                            type: 'rejectusername',
                            name: msg.name
                        };
                        connect.sendUTF(JSON.stringify(changeMsg));
                    }

                    connect.username = msg.name;
                    sendUserListToAll();
                    break;
            }

            if (sendToClients) {
                var msgString = JSON.stringify(msg);
                var i;

                for (i = 0; i < connectionArray.length; i+=1) {
                    connectionArray[i].sendUTF(msgString);
                }
            }
        }
    });

    connection.on('close', function(connection) {
        connectionArray = connectionArray.filter(function(el, idx, ar) {
            return el.connected;
        });
        sendUserListToAll();
    });
});
```
