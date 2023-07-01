# Hooks

[Built-in React Hooks – React](https://react.dev/reference/react)

## State Hooks
[useState](#useState)
[useReducer](#useReducer)
## Context Hooks
[useContext](#useContext)
## Ref Hooks
[useRef](#useRef)
## Effect Hooks
[useEffect](#useEffect)
## Performance Hooks
[useCallback](#useCallback)
[useMemo](#useMemo)
## Other Hooks
[useImperativeHandle](#useImperativeHandle)
[useLayoutEffect](#useLayoutEffect)
[useDebugValue](#useDebugValue)

## useState

`setState` function identity is stable and won't change on re-renders.

```js
const [state, setState] = useState(initialState)
setState(newState)
```

Functional updates

```js
import React, {useState} from 'react'

function Example() {
    const [count, setCount] = useState(0)
    setCount((prevCount) => prevCount + 1)
}
```

Bailing out of a state update

if updated state same as current state, React will bail out without rendering the children or firing effects.

## useEffect

do something after component render
such as data fetching or call some other imperative api

return a function to cleanup effects

pass an array as an options second argument to `useEffect` to skip apply an effect if certain values haven't changed between re-renders

```js
import React from 'react'

function useFetch(url, options) {
    const [response, setResponse] = React.useState(null)
    const [error, setError] = React.useState(null)
    React.useEffect(() => {
        const fetchData = async () => {
            try {
                const res = await fetch(url, options)
                const json = await res.json()
                setResponse(json)
            } catch (error) {
                setError(error)
            }
        }
        fetchData()
    }, [])
    return {response, error}
}
```

Cancel all subscriptions and asynchronous tasks in a useEffect cleanup function.

```js
useEffect(() => {
    // use AbortController to cancel fetch request
    const ab = new AbortController()
    async function get() {
        try {
            const res = await fetch(url, {signal: ab.signal})
            //
        } catch (error) {
            //
        }
    }
    get()
    return () => {
        ab.abort()
    }
}, [])
```

The clean up function runs before the component is removed from the UI to prevent memory leaks.

## useContext

```js
const value = useContext(MyContext)
```

## useReducer

```js
const initialState = {count: 0}

function reducer(state, action) {
    switch (action.type) {
        case 'in':
        return {count: state.count + 1}
        case 'de':
        return {count: state.count - 1}
        default
        throw new Error()
    }
}

function Counter() {
    const [state, dispatch] = useReducer(reducer, initialState)
    // render
    // dispatch({type: 'in'})
}
```

## useCallback
Lets you cache a function definition before passing it down to an optimized component.
Returns a memoized callback.
```js
const memoizedCallback = useCallback(() => doSomething(a, b), [a,b])
```

Example
```jsx
import { memo, useCallback, useRef, useState } from "react";

interface FormProps {
  onSubmit: () => void
}
function Form(props: FormProps) {
  const {onSubmit} = props
  const count = useRef(0)
  console.log('render count', count.current += 1);
  return (
    <div>foo</div>
  )
}

const MemoForm = memo(Form)

function App() {
  const [count, setCount] = useState(0)


  const memoCallback = useCallback(() => console.log('submit'), []);


  return (
    <div>
      <MemoForm onSubmit={memoCallback} />
      <button onClick={() => setCount(count +1)}>click</button>
    </div>
  )
}

export default App
```

## useMemo
Returns a memoized value.
```js
const memoizedValue = useMemo(() => computeExpensiveValue(a, b), [a, b])
```

## useRef
```js
const ref = useRef(initialValue)
```

```jsx
function TextWithFocusButton() {
    const ref = useRef(null)

    const click = () => {
        ref.current?.focus()
    }

    return (
        <>
            <input ref={ref} type="text">
            <button onClick={click}>Focus</button>
        </>
    )
}
```

### use case
```js
function Timer() {
    const intervalRef = useRef()

    useEffect(() => {
        intervalRef.current = setInterval(() => {
            // ...
        })

        return () => {
            clearInterval(intervalRef.current)
        }
    })
}

```