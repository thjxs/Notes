# Animation

## 顺畅的动画

`margin`, `top`, `left` 等属性可以达到相同的预期效果，但是如果使用 margin 就会涉及浏览器重排和重绘。
因此最佳的方案是使用 `transform` 属性

## keyframes

```css
@keyframes color-pop {
    0% {
        background-color: green;
    }
    33% {
        background-color: blue;
    }
    100% {
        background-color: orange;
    }
}

.test {
    animation: color-pop infinite 5s linear;
}
```
