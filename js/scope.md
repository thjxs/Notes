## function scope and hosting
JavaScript's function scope means that all variables declared within a function are visible *throughout* the body of the function

```js
function test(o) {
    var i = 0;
    if (typeof o == 'object') {
        var j = o;
    }
    for(var k = 0; k < 3; k += 1) {}

    // i is defined throughout function
    // j is defined, but may not be initialized
    // k is still defined: prints 3
}
```

## 函数的生命周期
创建
激活

## scope chain
top level, the scope chain consists of a single object, the global object.
In a non-nested function, the scope chain consists of two objects. The first is the object that defines the function's parameters and local variables, and the second is the global object.
In a nested function, the scope chain has three or more objects.

## nested function
each time the outer function is called, the inner function is defined again.
