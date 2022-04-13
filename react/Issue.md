# Issue

## setState

虚拟 DOM

设置状态时，组件会重新进行渲染，并阻止事件传播

## antd Iconfont
长列表渲染，Iconfont 造成较大的性能问题

### passive event listener

表示 `listener` 永远不会调用 `preventDefault()`。如果调用了这个函数，客户端将会忽略它并抛出一个控制台警告。

React 默认给 `touchstart`, `touchmove` 和 `wheel` 事件设置 `passive`。

一种方法解决滚轮事件不能调用 `preventDefault()`

```
const ref = useRef(null)

useEffect(() => {
	ref.current?.addEventListener((e) => e.preventDefault())
}, [])

function onWheel() {
	//
}

return (
	<div ref={ref} onWheel={onWheel}>
	...
	</div>
)
```

