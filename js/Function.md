# Function

## static

Static methods are designed to live only on the constructor in which they are created, and cannot be passed down to any children.

```js
class Chameleon {
    static colorChange(newColor) {
        this.color = newColor
        return this.color
    }
    constructor({newColor = 'green'} = {}) {
        this.color = newColor
    }
}

const freddie = new Chameleon({newColor: 'purple'})
console.log(freddie.colorChange('orange')) // TypeError
```

## bind

The `bind()` method creates a new function that, when called, has its `this` keyword set to the provided value, with a given sequence of arguments preceding and provided when the new function is called.

```js
this.x = 9
var module = {
    x: 81,
    getX: function() {return this.x}
}
module.getX() // 81
var retrieveX = module.getX
retrieveX() // 9
var boundGetX = retrieveX.bind(module)
boundGetX() //81
```

## apply

The `apply()` method calls a function with a given `this` value, and `arguments` provided as an array (or an array-like object)

> Beware of argument length

```js
var numbers = [5, 6, 2, 3, 7]
var max = Math.max.apply(null, numbers) // 7

var array = ['a', 'b']
var elements = [0, 1, 2]
// similar to array.concat(elements), but it creates a new array
array.push.apply(array, elements) // ['a', 'b', 0, 1, 2]
```
