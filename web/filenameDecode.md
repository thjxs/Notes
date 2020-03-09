当字符串处于ASCII编码问题时，使用`decodeURI`, `escape`
```
# eg
let str = 'ä¸­æ'
decodeURI(escape(str))
```
