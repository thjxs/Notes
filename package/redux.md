# redux

## setup

```sh
yarn create react-app my-app --template redux-typescript
```

## Example

```js
import {createStore} from 'redux'

function counterReducer(state = {value: 0}, action) {
    switch (action.type) {
        case 'counter/incremented':
            return {value: state.value + 1}
        case 'counter/decremented':
            return {value: state.value - 1}
        default:
            return state
    }
}

const store = createStore(counterReducer)

store.subscribe(() => console.log(store.getState()))

store.dispatch({type: 'counter/incremented'})
```
