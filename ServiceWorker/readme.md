# Service Worker

1. download
2. install
3. activate

## use case

* background data synchronization
* responding to resource requests from other origins
* receiving centralized updates to expensive to calculate data such as geolocation or gyroscope, so multiple pages can make use of one set of data.
* client side compiling and dependency management of coffeescript,less,cjs/amd modules, etc. for development purposes.
* hooks for background services.
* custom templating based on certain URL patterns.
* Performance enhancements, for example pre-fetching resources that the user is likely to need in the near future, such as the next few pictures in a photo album.

## cache

* match 返回匹配请求的第一个 `Cache` 对象
* matchAll 返回所有匹配请求的 `Cache` 对象
* add 接受一个 `URL`，并去检索这个资源并将响应的对象添加到 `cache`
* addAll 接受一个 `URL` 数组，检索资源并将响应对象添加到 `cache`
* put 接受一个`request` 和对应的 `response` 添加到 `cache`
* delete 根据 `request` 查询 `cache`，返回true表明删除成功，反之为 false
* keys 返回一个 `cache` 键值的数组

### cache storage

> 可以通过全局属性 `caches` 访问 `CacheStorage`

* match 通过 `request` 检索 `cache` 对象
* has 通过 `cacheName` 检索 `cache` 对象
* open 通过 `cacheName` 返回 `cache` 对象（不存在，则新建一个）
* delete 删除 `cache` 对象
* keys 返回所有命名的 `cache` 对象

### Client

代表一个可执行的上下文，如 `Worker` ，`SharedWorker`

* postMessage 发送消息

### Clients

* get 获取一个 `client`
* matchAll 返回一个 `client` 的对象数组
* openWindow 打开一个新窗口
* claim 将控制权交给激活 SW

### ExtendableEvent

延长 SW 安装和激活事件的生命周期，确保在升级数据库并删除过时的 caches 之前，不会调度任何事件函数。

方法 `waitUntil` 用于延长事件的生存期

### ExtendableMessageEvent
* data
* origin
* lastEventId
* source
* ports

### FetchEvent
在 service worker 的全局作用域触发的 fetch 事件。`event.respondWith` 方法允许我们提供一个响应给该fetch
* clientId 发起 fetch 的客户端 ID
* preloadResponse 预加载响应
* replacesClientId 由页面导航被替换的页面客户端ID
* resultingClientId 页面导航之后的客户端ID
* request 浏览器发起的请求
* responseWith 使用自己提供的响应
* waitUntil 延长事件的生存期

### NavigationPreloadManager
todo

### Navigator.serviceWorker
返回 `ServiceWorkerContainer` 对象

### NotificationEvent
代表通知点击事件
* notification
* action
* waitUntil

### ServiceWorker
* scriptURL 返回序列化的脚步URL
* state service worker的状态：installing, installed, activating, activated, or redundant
* onstatechange 监听 state 的变化事件

### ServiceWorkerContainer
* controller 返回 `ServiceWorker` 对象
* ready 让代码延时执行，直到 service worker 被激活
* controllerchange 当 document 关联的 ServiceWorkerRegistration 获得一个新的激活的 worker
* error service workers 发生错误时
* message 接收到消息时触发
* register 创建或更新一个 ServiceWorkerRegistration
* getRegistration
* getRegistrations
* startMessages

### ServiceWorkerGlobalScope
service worker 的执行上下文
#### Properties
* caches 包含与 service worker 关联的 `CacheStorage` 对象
* clients 包含与 service worker 关联的 `Clients` 对象
#### Events
* activate 当 `ServiceWorkerRegistration` 获得一个新的活跃worker触发
* contentdelete 当Content Index删除条目时出现
* fetch `fetch()` 调用时出现
* install 当 `ServiceWorkerRegistration` 获得一个新的安装中的worker触发
* message 接收消息
* notificationclick 点击通知
* notificationclose 关闭通知
* periodicsync 
* push
* pushsubscriptionchange
* sync

#### Methods
* skipWaiting 强制将等待的service worker变更为激活状态
* fetch 处理资源获取