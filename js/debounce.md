```js
function debounce(func, wait) {
    let timeout;
    return function () {
        let context = this
        let args = arguments
        let later = function () {
            timeout = null
            func.apply(context, args)
        }
        clearTimeout(timeout)
        timeout = setTimeout(later, wait);
    }
}
```

## keywords
[arguments](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/arguments)
