# Child process

The `child_process` module provides the ability to spawn subprocesses in a manner that is similar, but not identical, to `popen(3)`. This capability is primarily provided by the `child_process.spawn()` function. 

## Asynchronous process creation

The `child_process.spawn()`, `child_process.fork()`, `child_process.exec()`, and `child_process.execFile()` methods all follow the idiomatic asynchronous programming pattern typical of other Node.js APIs.

Each of the methods returns a `ChildProcess` instance. These objects implement the Node.js `EventEmitter` API, allowing the parent process to register listener functions that are called when certain events occur during the life cycle of the child process.

## spawn

```js
const { spawn } = require('child_process')

const ps = spawn('ps', ['ax'])

const grep = spawn('grep', ['ssh'])

ps.stdout.on('data', (data) => {
    grep.stdin.write(data)
})

ps.stderr.on('data', (data) => {
    console.error(`ps stderr: ${data}`)
})

ps.on('close', (code) => {
    if(code !== 0) {
        console.log('ps exited with code ${code}')
    }
    grep.stdin.end()
})

grep.stdout.on('data', (data) => {
    console.log(data.toString())
})

grep.stderr.on('data', (data) => {
    console.error(`grep stderr ${data}`)
})

grep.on('close', (code) => {
    if(code !== 0) {
        console.log('grep exited with code ${code}')
    }
})
```
