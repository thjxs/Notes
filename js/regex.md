## RegExp.prototype.test()
当设置 g 标志时，`test()` 的执行会改变正则表达式 `lastIndex` 属性
```js
let nr = /\d/g
nr.test('123') // true
nr.test('123') // true
nr.test('123') // true
nr.test('123') // false
```

## example
```js
function highlightParas(containing) {
    if (typeof containing === 'string') {
        containing = new RegExp(`\\b${containing}\\b`, 'i');
    }

    const paras = document.getElementsByTagName('p')

    for(let p of paras) {
        if (! containing.test(p.textContent)) {continue}
        p.classList.add('highlight')
    }
}
```
