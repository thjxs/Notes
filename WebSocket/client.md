```js
"use strict";

var connection = null;
var clientID = 0;

function connect() {
    var serverUrl;
    var scheme = 'ws';

    if (document.location.protocol === 'https:') {
        scheme += 's';
    }

    serverUrl = scheme + '://home.test:6502';

    connection = new WebSocket(serverUrl, 'json');

    connection.onopen = function (event) {
        console.log('connected');
        connection.send(JSON.stringify({text: 'hi', type: 'message'}));
    }

    connection.onmessage = function (event) {
        console.log(JSON.parse(event.data));
    }
}
```
