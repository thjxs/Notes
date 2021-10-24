# Redux

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

### State shape

```js
{
    visibilityFilter: 'SHOW_ALL',
    todos: [
        {
            text: 'Consider using Redux',
            completed: true
        },
        {
            text: 'Keep all state in a single tree',
            completed: false
        }
    ]
}
```

### handling actions

The reducer is a pure function that takes the previous state and an action, and returns the next state.

```js
(previousState, action) => newState
```

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
    case ADD_TODO:
      return [
        ...state,
        {
          text: action.text,
          completed: false
        }
      ]
    case TOGGLE_TODO:
      return state.map((todo, index) => {
        if (index === action.index) {
          return Object.assign({}, todo, {
            completed: !todo.completed
          })
        }
        return todo
      })
    default:
      return state
  }
}

const todoApp = combineReducers({
  visibilityFilter,
  todos
})

export default todoApp
```
