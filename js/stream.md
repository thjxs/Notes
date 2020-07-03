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

## Web APIs
ReadableStream, The `ReadableStream` constructor creates and returns a readable stream object from the given handlers

## blob to readableStream
```js
class BlobStreamController {
    constructor(blob) {
        this.chunkSize = 1024 * 64
        this.blob = blob
    }
    start(controller) {
        const reader = new FileReader()
        reader.onload = () => {
            const ui8 = new Uint8Array(reader.result)
            const endFitIndex = Math.floor(ui8.length / this.chunkSize) * this.chunkSize
            for (let i = 0; i < endFitIndex; i += this.chunkSize) {
                controller.enqueue(ui8.slice(i, i + this.chunkSize))
            }
            if (ui8.length - endFitIndex > 0) {
                controller.enqueue(ui8.slice(endFitIndex, ui8.length))
            }
            controller.close()
        }
        reader.readAsArrayBuffer(this.blob)
    }
}
```

### demo
```js
let result = ''
function randomChars() {
    let string = ''
    let choices = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'
    for (let i = 0; i < 8; i += 1) {
        string += choices.charAt(Math.floor(Math.random() * choices.length))
    }
    return string
}

const stream = new ReadableStream({
    start(controller) {
        interval = setInterval(() => {
            let string = randomChars()

            controller.enqueue(string)
        })
    }
})
```
