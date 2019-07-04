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
