# match parentheses

```js
let isValid = function (str) {
    const stack = [];
    const mapper = {
        ')': '(',
        ']': '[',
        '}': '{',
    },
    const leftParentheses = ['(', '[', '{'];

    for (let i in str) {
        if (leftParentheses.indexOf(str[i])> -1) {
            stack.push(str[i])
        } else {
            if (mapper[str[i]] !== stack.pop()) {
                return false
            }
        }
    }

    if (stack.length > 0) return false;
    return true;
}

const testStr = [
"{[]}",                                                                         
"([)]",                                                                         
"(]",                                                                           
"()[]{}",                                                                       
"()", 
];

testStr.map(str => {
    console.log(isValid(str))
})
```
