```js
const http = require("http");

const express = require("express");

const {
  createProxyMiddleware,
  responseInterceptor,
} = require("http-proxy-middleware");

const { TARGET } = process.env;

const port = process.env.port ?? 3945

let hostname = 'xx.com'

{
  switch (TARGET) {
    case "office3":
      hostname = "192.168.2.192";
      break;

    case "uat":
      target = "cc.com";
      break;

    default:
      target = "xx.com";
      break;
  }
}

let token = "";

let count = 0;

let target = 'http://' + hostname

function onProxyReq(proxyReq, req, res) {
  // 服务器可能检查 Header 的referrer，所以设置一下来源
  proxyReq.setHeader("referer", target);
  const isLogin = proxyReq.path.match(/login/);
  if (!isLogin && token) {
    proxyReq.setHeader("Authorization", token);
  }
}

const onProxyRes = responseInterceptor(async (buffer, proxyRes, req, res) => {
  const isJson = /application\/json/;

  if (isJson.test(proxyRes.headers["content-type"])) {
    try {
      const res = JSON.parse(buffer.toString("utf-8"));
      if (res.code === 401) {
        console.log("login count: ", (count += 1));
        login();
      }
      if (res.token) {
        console.log("login count: ", (count += 1));
        token = res.token;
      }
    } catch (error) {
      console.error(error);
    }
  }
  return buffer;
});

function login() {
  const options = {
    hostname,
    path: "/login",
    method: "post",
    headers: {
      "Content-Type": "application/json",
    },
  };

  const req = http.request(options, (res) => {
    let rawData = "";
    res.on("data", (chunk) => (rawData += chunk));
    res.on("end", () => {
      try {
        const parsedData = JSON.parse(rawData);
        token = parsedData.token;
      } catch (error) {}
    });
  });

  req.on("error", (error) => {
    console.error(error);
  });

  req.write(JSON.stringify({ password: "admin123", username: "admin" }));
  req.end();
}

const options = {
  target,
  changeOrigin: true,
  selfHandleResponse: true,
  onProxyReq,
  onProxyRes,
};

const proxy = createProxyMiddleware("/", options);

const app = express();

app.use(proxy);

app.listen(port);

login();

```