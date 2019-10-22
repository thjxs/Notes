## Refs provide a way to access DOM nodes or React elements created in the render method.

## use cases
* Managing focus, text selection, or media playback.
* Triggering imperative animations.
* Integrating with third-party DOM libraries

## creating refs
```js
class MyComponent extends React.Component {
    constructor(props) {
        super(props)
        this.myRef = React.createRef();
    }

    render() {
        return <div ref={this.myRef} />
    }
}
```
