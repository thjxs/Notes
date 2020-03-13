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