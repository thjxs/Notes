# Debounce & Throttle

* throttling: sample changes based on a time based frequency
* debouncing: publish changes after a period of inactivity

[comparison of throttle and debounce](http://demo.nimius.net/debounce_throttle/)

## Debounce

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
