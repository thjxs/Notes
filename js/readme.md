## const 
声明创建一个常量，其作用域可以是全局或本地声明的块。
const 声明创建一个值的只读引用
如果引用内容是对象的情况下，意味着可以改变对象的内容

```js
const obj = {
    name: 'Tan',
    age: '23'
}

// "CC"
obj.name = 'CC'
```

## >>> (zero fill right shift)
```
9 (base 10): 00000000000000000000000000001001 (base 2)
9 >>> 2 (base 10): 00000000000000000000000000000010 (base 2) = 2 (base 10)

-9 (base 10): 11111111111111111111111111110111 (base 2)
-9 >>> 2 (base 10): 00111111111111111111111111111101 (base 2) = 1073741821 (base 10)
```

## Hoisting
JavaScript Hoisting: In JavaScript, ervry variable declaration is hoisted to the 
top of its declaration context.

用函数声明创建的函数可以在函数解析后调用（解析时进行逻辑等处理），
而函数表达式创建的函数是在运行时进行赋值， 所以要等待表达式赋值完成后才能调用
```
funDeclaration("Declaration");  //true
function funDeclaration(type) {
    return type === "Declaration";
}

funExpression("Expression");  //error
funExpression(Expression) {
    return === "Expression"
}

```


## toFixed
返回固定小数位的字符
```js
const number = 123.456

// 123.46
number.toFixed(2)
```

## getComputedStyle
```js
const getStyle = (el, ruleName)  => getComputedStyle(el)[ruleName];

getStyle(document.body, 'font-size'); // '16px'
```

## hasClass
```js
const hasClass = (el, className) => el.classList.contains(className);

hasClass(document.querySelector('p.special'), 'special');
```

## early exit 
```js
const printAnimalDetails = ({type, name, gender}) => {
    if (!type) return 'no type';
    if (!name) return 'no name';
    if (!gender) return 'no gender';
}
```

## async promise setTimeout
```js
async function a1() {
    console.log('a1')
    await a2()
    console.log('a1 end')
}
async function a2() {
    console.log('a2')
}
console.log('start')
a1()
setTimeout(() => {
    console.log('s1')
}, 0)
new Promise((res, rej) => {
    console.log('p1')
    res()
}).then(() => {
    console.log('p then')
})
console.log('end')
```

## DOMHighResTimeStamp
The value of a `DOMHighResTimeStamp` is a double-precision floating-point number which describes the number of milliseconds (accurate to within 5 microseconds if the device supports it) elapsed between two points in time. The starting time can be either a specific time determined by the script for a site or app, or the time origin.
