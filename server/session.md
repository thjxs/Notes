# SESSION

session 用于存储用户会话的信息

当开始一个会话时，PHP 尝试从请求中查找会话 ID，没有则创建一个新的会话，会话数据存储在 `$_SESSION` 变量中

当 PHP 停止时，它会读取 `$_SESSION` 的内容，并进行序列化，然后发送给会话管理器保存。

PHP 脚本执行完毕之后，会话自动关闭或者显示调用 `session_write_close`() .

基于文件的会话数据保存，在会话开始的时候跟会话数据文件加锁。直到显式调用 `session_write_close()` 或脚本执行完毕。在此期间，其它脚本不可以访问同一个会话数据文件。

对于大量的 Ajax 和并发请求，应该尽快释放文件锁，或者选择支持并发操作的会话管理器。

session 的传递方式

* cookies
* URL 参数

## 会话管理

自定义会话管理器

通过 `SessionHandlerInterface` 或者继承 `SessionHandler` 类，需要实现的回调函数 open read write close, 垃圾清理 destroy gc

内置的会话管理器 files, sqlite, memcache, memcached
