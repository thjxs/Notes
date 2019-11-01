## filter
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

## includes
```js
const animals = ['dog', 'cat', 'hamster']
if (animals.includes('dog')) {
    console.log('dog')
}
```
