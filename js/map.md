# Map

The `Map` object holds key-value pairs and remembers the original insertion order of the keys.
Any value (both objects and primitive values) may be used as either a key or a value.

```js
const m1 = new Map()
const keyString = 'a string'
const keyObj = {}
const keyFunc = function() {}

m1.set(keyString, 'value of stirng')
m1.set(keyObj, 'value of obj')
m1.set(keyFunc, 'value of func')

m1.size

m1.get(keyString)
m1.get(keyObj)
m1.get(keyFunc)
m1.get('a string')
m1.get({})
m1.get(function() {})

// for..of
for(let [key, value] of m1) {
    console.log(key + '= ' + value)
}
m1.forEach(function(value, key) {
    console.log(key + '= ' + value)
})

const original = new Map([
    [1, 'one']
])

const clone = new Map(original)

original === clone // false. Useful for shallow comparison

// merge
const first = new Map([
    [1, 'one'],
    [2, 'two'],
    [3, 'three'],
])
const second = new Map([
    [1, 'uno'],
    [2, 'dos']
])

const merge = new Map([...first, ...second])

```

## WeakMap

```js
const wm1 = new WeakMap()
const wm2 = new WeakMap()
const wm3 = new WeakMap()
const o1 = {}
const o2 = function() {}
const o3 = window

wm1.set(o1, 37)
wm1.set(o2, 'azerty')
wm2.set(o1, o2)
wm2.set(o3, undefined)
wm2.set(wm1, wm2)

wm1.get(o2)
wm2.get(o2)
wm2.get(o3)
```
