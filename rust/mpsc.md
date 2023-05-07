multi-producer, single-consumer
mpsc 模块基于消息的信道通信，定义了三种类型
- Sender
- SyncSender
- Receiver

Sender 或者 SyncSender 用来发送数据到 Receiver，这些 Sender 都可以克隆。

```rust
use std::thread;
use std::sync::mpsc::channel;

let (tx, rx) = channel();

thread::spawn(move|| {
	tx.send(10).unwrap();
});

assert_eq!(rx.recv().unwrap(), 10);
```