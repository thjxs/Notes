# Refs

通过ref直接访问React生成的DOM节点

## use cases

* Managing focus, text selection, or media playback.
* Triggering imperative animations.
* Integrating with third-party DOM libraries

## creating refs

```jsx
import {useRef} from 'react'

function Foo() {
  const myRef = useRef(null)

  myRef.current.scrollIntoView()

  return (
    <div ref={myRef}></div>
  )
}

```

## Accessing component's DOM nodes

```jsx
const MyInput = forwardRef((props, ref) => {
  return (
    <>
      <label>{props.label}</label>
      <input {...props} ref={ref} />
    </>
  );
});

function MyForm() {
  const inputRef = useRef(null);
  function handleClick() {
    inputRef.current.focus();
  }
  return (
    <>
      <MyInput label="name" ref={inputRef} />
      <button onClick={handleClick}>focus the input</button>
    </>
  );
}
```

## When React attaches the refs

React 每次更新分为两个阶段

- render，调用组件来收集变更
- commit，将变更应用到 DOM

所以首次渲染的时候，DOM 节点还没创建， `ref.current` 是 null
重新渲染的时候，DOM 也还没更新，这时去读 `ref.current` 是过早的。

那设置 ref 就发生在 commit 的时候，在 DOM 更新之前，React 将 ref 设置为 null，更新 DOM 之后，立即将对应的 DOM 节点设置到 ref

在组件 rerender 的时候，ref 会经历 detach 到 attach 的阶段

```jsx
function MyButton() {
  function ref(target) {
	  console.log(target)
  }

  return (<button ref={ref}>button</button>)
}
```
