## The *Promise* object represents the eventual completion (or failure) of an asynchronous operation, and its resulting value.

### Syntax
`new Promise(executor)`
the executor is called before the `Promise` constructor even returns the created object

A `Promise` is in one of these states:
* pending
* fulfilled
* rejected

As the `Promise.prototype.then()` and `Promise.prototype.catch()` methods return promises, they can be chained

```js
let promise = new Promise((resolve, reject) => {
    // do something
    // resolve(someValue)
    // or
    // reject('failure reason')
})

promise.then(console.log).catch(console.log)
```

## all
```js
function countdown(seconds) {
    return new Promise(function(resolve, reject) {
        for(let i = seconds; i >= 0; i -= 1) {
            setTimeout(function() {
                if (i > 0) {
                    console.log(seconds + ': ' + i)
                } else {
                    resolve(seconds)
                }
            }, (seconds - i) * 1000)
        }
    })
}

Promise.all([countdown(6), countdown(8)]).then(res => {
    console.log(res)
})
```

## async map
```js
const assert = require('assert');
function timesTwoAsync(x) {
    return new Promise(resolve => resolve(x * 2));
}

const arr = [1, 2, 3];
const promiseArr = arr.map(timesTwoAsync);
Promise.all(promiseArr).then(result => {
    assert.deepEqual(result, [2, 4, 6]);
})
```

## race
The `Promise.race()` method returns a promise that fulfills or rejects 
as soon as one of the promise in an iterable fulfills or rejects, with the value
or reason from that promise

```js
Promise.race([countdown(3), countdown(5)]).then(value => {
    console.log(value)
})
```

## Converting callbacks to promises
```js
const fs = require('fs')
fs.readFile(filePath, options, callback)
const readFilePromise = (...args) => {
    return new Promise((resolve, reject) => {
        fs.readFile(...args, (err, data) => {
            if (err) return reject(err)
                resolve(data)
        })
    })
}
```
