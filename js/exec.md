## copy
```js
const selection = window.getSelection()
const target = document.getElementById('target')
if (selection.rangeCount > 0) {
    selection.removeAllRanges()
}
const range = document.createRange()
range.selectNode(target)
selection.addRange(range)
document.execCommand('copy')
```
