# lazy
let you define a component that is loaded dynamically

> requires a polyfill on IE 11 

## lazy type
```jsx
const lazyType: LazyComponent<T, Payload<T>> = {
    $$typeof: REACT_LAZY_TYPE,
    _payload: payload, // store the result
    _init: lazyInitializer
}
```
