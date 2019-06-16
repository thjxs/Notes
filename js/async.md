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
