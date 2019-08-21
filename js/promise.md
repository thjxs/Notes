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

const all = Promise.all([countdown(6), countdown(8)])
all.then(res => {
    console.log(res)
})
```
