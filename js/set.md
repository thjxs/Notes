## Set
The `Set` object lets you store unique values of any type, whether primitive values
or object references.

```js
const set1 = new Set([1, 5])
const o = {a: 1, b: 2}
set1.add(0)
set1.add({a: 1, b: 2})
console.log(set1)

for(let item of set1) console.log(item)

// reomve duplicate elements
const numbers = [2,3,4,5,6,2,3,5]
console.log([...new Set(numbers)])
```

## WeakSet
The `WeakSet` object lets you store weakly held *objects* in a collection
```js
const ws = new WeakSet()
const foo = {}
const bar = {}
ws.add(foo)
ws.add(bar)
ws.has(foo)
ws.has(bar)
ws.delete(foo)
ws.has(foo)
```
