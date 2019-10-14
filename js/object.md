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
