# Array

## concat

Merge two or more arrays, returns a new array.

```js
const arr1 = [1, 2, 3]
const arr2 = [4, 5, 6]

const arr3 = arr1.concat(arr2)
// [1, 2, 3, 4, 5, 6]
```

## entries

returns a new Array iterator object that contains the key/value pairs for each index in the array

## every

The every method test whether all elements in the array pass the test implemented by the provided function. It returns a Boolean value.

```js
const arr = [1, 2, 3, 4, 5]

arr.every(i => i < 10)
```

## filter

The filter method creates a new array with all elements that pass the test implemented by the provided function.

```js
const targetIds = [1,3,5]
const arr = [
    { id: 1, name: 'cc',},
    { id: 2, name: 'cc',},
    { id: 3, name: 'cc',},
    { id: 4, name: 'cc',},
    { id: 5, name: 'cc',},
]
const targetArr = arr.filter(item => targetIds.indexOf(item.id) !== -1)
```

## find

The find method returns the value of the first element in the provided array that satisfies the provided testing function. If no values satisfy the testing function, `undefined` is returned.

```js
const array = [1, 2, 3]

const found = array.find(e => e > 2)
```

## findIndex

The `findIndex` method returns the index of the first element in the array that satisfies the provided testing function. Otherwise, it returns `-1`, indicating that no element passed the test.

```js
const array = [4,12,18]

const index = array.findIndex(e => e > 12)
```

## includes

The includes method determines whether an array includes a certain value among its entries, returning `true` or `false` as appropriate.

```js
const animals = ['dog', 'cat', 'hamster']
if (animals.includes('dog')) {
    console.log('dog')
}
```

## indexOf

The `indexOf` method returns the first index at which a given element can be found in the array, or -1 if it is not present.

```js
const beasts = ['ant', 'bison', 'camel', 'bison']

beasts.indexOf('bison')

beasts.indexOf('bison', 2)
```

## reduce

```js
const arr = [1,2,3]
const sum = arr.reduce((a, x) => a += x, 0)
```
