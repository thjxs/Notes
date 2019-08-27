## The *Promise* object represents the eventual completion (or failure) of an asynchronous operation, and its resulting value.

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
