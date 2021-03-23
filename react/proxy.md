# [Proxy](https://create-react-app.dev/docs/proxying-api-requests-in-development/#configuring-the-proxy-manually)

* add `proxy` field into `package.json`
* create `src/setupProxy.js` file

## Configuring the proxy manually
First, add `http-proxy-middleware` [package](https://github.com/chimurai/http-proxy-middleware#http-proxy-options), then create `src/setupProxy.js`

```
const { createProxyMiddleware } = require('http-proxy-middleware');

module.exports = function (app) {
    app.use(
        '/api',
        createProxyMiddleware({
            target: 'http://localhost:5000',
            changeOrigin: true,
        })
    );
};
```
