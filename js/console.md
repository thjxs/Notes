## timers
```js
console.time('answer time');
setTimeout(function () {
    console.timeLog('answer time');
}, 500);
setTimeout(function () {
    console.timeEnd('answer time');
}, 3000);
```

## traces
```js
function foo() {
    function bar() {
        console.trace();
    }
    bar();
}
foo();
```
