# http-proxy-middleware

```js
const express = require('express');
const { createProxyMiddleware } = require('http-proxy-middleware');

const target = 'your server'

const options = {
  target,
  ws: true,
  changeOrigin: true,
  onProxyReqWs(proxyReq, req, socket) {
    socket.on('error', console.log); // handle error manauly
  },
};

const proxy = createProxyMiddleware('/', options);

const app = express();
app.use(proxy);
const server = app.listen(6050);

server.on('upgrade', proxy.upgrade); // proxy WebSocket, need upgrade

```
