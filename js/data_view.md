## DataView
`DataView` 视图是一个可以从二进制 `ArrayBuffer` 对象中读写多种数值类型的底层接口，使用它时，不用考虑不同平台的[字节序](https://developer.mozilla.org/zh-CN/docs/Glossary/Endianness)问题。

## 语法
```js
new DataView(buffer[, byteOffset [, byteLength]])
```