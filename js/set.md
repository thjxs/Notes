# Set

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

## Implementing basic set operations

```js
function isSuperset(set, subset) {
    for (let elem of subset) {
        if (!set.has(elem)) return false;
    }
    return true
}

function union(setA, setB) {
    let _union = new Set(setA)
    for (let elem of setB) {
        _union.add(elem)
    }
    return _union
}

function intersection(setA, setB) {
    let _intersection = new Set()
    for (let elem of setB) {
        if (setA.has(elem)) {
            _intersection.add(elem)
        }
    }
    return _intersection
}

function symmetricDifference(setA, setB) {
    let _difference = new Set(setA)
    for (let elem of setB) {
        if (_difference.has(elem)) {
            _difference.delete(elem)
        } else {
            _difference.add(elem)
        }
    }
    return _difference
}

function difference(setA, setB) {
    let _difference = new Set(setA)
    for (let elem of setB) {
        _difference.delete(elem)
    }
    return _difference
}
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
