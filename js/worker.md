## Web Workers API
It represents a background task that can be easily created and can send messages back to its creator.

## demo
```js
const workerBlob = new Blob([`function parse (time) {
    const start = new Date()
    while(new Date() - start < time) {}
    return true
}

onmessage = function (e) {
    postMessage(parse(e.data))
}`], {type: 'application/javascript'})
const workerURL = URL.createObjectURL(workerBlob)

const wk = new Worker(workerURL)
wk.postMessage(1000)
wk.addEventListener('message', (e) => {
    console.log(e.data)
})
```
