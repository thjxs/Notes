## bind

The `bind()` method creates a new function that, when called, has its `this` keyword set to the provided value, with a given sequence of arguments preceding and provided when the new function is called.

```js
this.x = 9
var module = {
    x: 81,
    getX: function() {return this.x}
}
module.getX() // 81
var retrieveX = module.getX()
retrieveX() // 9
var boundGetX = retrieveX.bind(module)
boundGetX() //81
```
