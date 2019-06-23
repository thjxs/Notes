## crypto
提供了加密功能，包括对 OpenSSL 的哈希、HMAC、加密、解密、签名、以及验证功能的一整套封装

## hash
```js
const crypto = require('crypto')
const hash = crypto.createHash('sha256')

hash.on('readable', () => {
    const data = hash.read()
    if (data) {
        console.log(data.toString('hex'))
    }
})

hash.write('string')
hash.end()
```
