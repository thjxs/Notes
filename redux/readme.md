## action
An action is a plain JavaScript object that describes what happened
```js
{type: 'ADD_TODO', text: 'go to swimming pool'}
{type: 'TOGGLE_TODO', index: 1}
```

### action creators
action creators simply return an action
```js
function addTodo(text) {
    return {
        type: ADD_TODO,
        text
    }
}
```

## reducer
takes state and action as arguments, and returns the next state of the app.

* **DO NOT** mutate the state
* return the previous state in the default case

```js
function visibilityFilter(state = 'SHOW_ALL', action) {
    if (action.type === 'SET_VISIBILITY_FILTER') {
        return action.filter
    } else {
        return state
    }
}
```
## tutorial
```js
function visibilityFilter(state = 'SHOW_ALL', action) {
    switch (action.type) {
        case 'SET_VISIBILITY_FILTER':
            return action.filter
        default: 
            return state
    }
}

function todos(state = [], action) {
    switch (action.type) {
        case 'ADD_TODO':
         return [
        ]
    }
}
```
