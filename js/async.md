## Promise
```js
function countdown(seconds) {
    return new Promise((resolve, reject) => {
        for (let i=seconds; i>=0; i-=1) {
            setTimeout(() => {
                if (i > 0) {
                    console.log(i + '..');
                } else resolve(console.log('go'));
            }, (seconds-i)*1000)
        }
    });
}
```

## yield
```js
function* interrogate() {
    const name = yield 'name';
    const color = yield 'color';
    return `${name} = ${color}`;
}
```

## async
Return value: A `Promise` which sill be resolved with the value returned by the async
function, or rejected with an uncaught exception thrown from within the async function
```js
function resolveAfter2Seconds(x) {
    return new Promise(resolve => {
        setTimeout(() => {
            resolve(x);
        }, 2000);
    });
};

var add = async function(x) {
    var a = await resolveAfter2Seconds(22);
    var b = await resolveAfter2Seconds(23);
    return x + a + b;
};

add(10).then(v => {
    console.log(v)
})
```
