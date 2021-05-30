[useState](#useState)
[useEffect](#useEffect)
[useContext](#useContext)
[useReducer](#useReducer)
[useCallback](#useCallback)
[useMemo](#useMemo)
[useRef](#useRef)
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

**return a function to cleanup effects**

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
