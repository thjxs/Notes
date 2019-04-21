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
