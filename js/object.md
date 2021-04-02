## Property 
*value*, *writable*, *enumerable*, and *configurable*

```js
Object.getOwnPropertyDescriptor({x: 1}, 'x');
// {value: 1, writable: true, enumerable: true, configurable: true}
```

## Getters and Setters
Properties defined by getters and setters are sometimes known as *accessor properties* to distinguish them from *data properties* that have a simple value.

```js
var p = {
    x: 1.0,
    y: 1.0,

    get r() {
        return Math.sqrt(this.x * this.x + this.y * this.y)
    }
    set r(value) {
        var oldvalue = Math.sqrt(this.x*this.x + this.y*this.y);
        var ratio = value / oldvalue;
        this.x *= ratio
        this.y *= ratio
    }

    get theta() {
        return Math.atan2(this.y, this.x);
    }
}
```

## `__proto__`
It will overwrite Object's method, be careful using in production.

```js
const cache = {}
cache['__proto__'].foo = 123
const anotherCache = {}
console.log(foo)
console.log(anotherCache.foo)
```

## Private field declarations
```js
class Rectanble {
    #height = 0;
    #width;
    constructor(height, width) {
        this.#height = height;
        this.#width = width;
    }
}
```

## The `new` keyword

* Creates a blank, plain JavaScript object
* Links (sets the constructor of) this object to another object
* Passes the newly created object from Step 1 as the this context
* Returns `this` if the function doesn't return its own object

## eg
```js
function Person(fn, ln) {
    this.firstName = fn
    this.lastName = ln
}

const lydia = new Person('Lydia', 'Hallie')
const sarah = Person('Sarah', 'Smith') // this refers to the global object
```

## Object keys
Object keys are automatically converted into strings.

```js
const a = {}
const b = {key: 'b'}
a[b] = 123
console.log(a) //{'[object Object]': 123}
```
