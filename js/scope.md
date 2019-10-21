## 函数的生命周期
创建
激活

## scope chain
top level, the scope chain consists of a single object, the global object.
In a non-nested function, the scope chain consists of two objects. The first is the object that defines the function's parameters and local variables, and the second is the global object.
In a nested function, the scope chain has three or more objects.

## nested function
each time the outer function is called, the inner function is defined again.
