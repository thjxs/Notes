智能指针，提供对类型 T 的值的共享所有权，该值在堆中分配。
`Arc<T>` 类型是一种线程安全的引用计数指针，它可以让你在线程之间共享不可变数据。
当调用 clone 方法时，会创建一个新的的 Arc 实例，该实例指向与源 Arc 相同的堆上分配，同时增加引用计数。当最后一个 Arc 指针消失时，该分配将被释放。

```rust
use std::sync::Arc;
let foo = Arc::new(vec![1.0, 2.0, 3.0]);

let a = foo.clone();
let b = Arc::clone(&foo);
```