是一种互斥原语，用于保护共享数据。
这个互斥锁将阻塞等待锁变得可用的线程。
每个 Mutex 都有一个类型参数，表示它正在保护的数据。
该数据只能通过从 lock 和 try_lock 返回的 RAII 保护来访问。

```rust
use std::sync::mpsc::channel;
use std::sync::{Arc, Mutex};
use std::thread;

fn main() {
    const N: usize = 10;
    let data = Arc::new(Mutex::new(0));
    let (tx, rx) = channel();

    for _ in 0..N {
        let (data, tx) = (Arc::clone(&data), tx.clone());

        thread::spawn(move || {
            let mut data = data.lock().unwrap();
            *data += 1;
            if *data == N {
                tx.send(()).unwrap();
            }
        });
    }
    rx.recv().unwrap();
}

```