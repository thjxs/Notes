## requestAnimationFrame
Call function on every requestAnimationFrame. With controls of pausing and resuming.

```js
function useRAF(fn) {
    const ref = {
        stopped: false
    }
    function resume() {
        if (ref.stopped) {
            ref.stopped = false
            loop()
        }
    }
    function pause() {
        ref.stopped = true
    }
    function loop() {
        if (ref.stopped) {
            return
        }
        fn()
        requestAnimationFrame(loop)
    }

    return {pause, resume}
}
```
