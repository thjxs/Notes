# Context

Context provides a way to pass data through the component tree without having to pass props down manually at every level.

## API

* createContext
* Provider
* contextType // class component
* Context.Consumer // function component
* Context.displayName

## Hooks

* useContext

## example

```js
// context
import React from 'react'
export const themes = {
    light: '#000',
    dark: '#fff'
}

export const ThemeContext = React.createContext(themes.dark)

// button
import {ThemeContext} from './context'

class ThemedButton extends React.Component {
    render() {
        const theme = this.context
        // ...
    }
}
ThemedButton.contextType = ThemeContext
```
