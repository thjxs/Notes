The Streams API allows JavaScript to programmatically access streams of data received over the network and process them as desired by the developer.

## Types of Streams
* Writable
* Readable
* Duplex
* Transform

## example
```js
const fs = require('fs') 
const file = fs.createWriteStream('./big')
let i = 1e3
while(i--) {
    file.write('hello\n')
}
file.end()

const server = require('http').createServer()
server.on('request', (req, res) => {
    const src = fs.createReadStream('./big')
    src.pipe(res)
})

server.listen(9001)
```
