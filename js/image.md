# Image

使用 `crossorigin` 属性和合适的 `CORS` 响应头，就能够实现在画布中使用跨域 `<img>` 元素的图像

## 存储外部域的图片

```js
function download(url) {
    const img = new Image()
    img.crossOrigin = 'anonymous' // use-credentials
    img.addEventListener('load', () => received(img), false)
    img.src = url
}

function received(img) {
    const canvas = document.createElement('canvas')
    const context = canvas.getContext('2d')
    canvas.width = img.width
    canvas.height = img.height
    context.drawImage(img, 0, 0)
    document.body.appendChild(canvas)

    try {
        localStorage.setItem('saved-image', canvas.toDataURL('image/png'))
    } catch (error) {

    }
}
```
