## this
A functions's `this` keyword behaves a little differently in JavaScript compared to other languages.
It also has some differences between strict mode and non-strict mode.

## Value
A property of an execution context (global, function or eval) that, in non-strict mode, is always a reference to an object and in strict mode can be any value.

## demo 
```js
var test = {
    prop: 34,
    func: function() {
        return this.prop
    }
}

console.log(test.func())
```
