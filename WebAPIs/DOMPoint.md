# DOMPoint

A DOMPoint object represents a 2D or 3D point in a coordinate system

## Examples

```js
/**
 * 从鼠标事件拿到 `clientX`, `clientY`
 * 转换到 SVG 对应的点
 */
function translateToSVG(svg, points) {
    const output = []
    const matrix = svg.getScreenCTM().inverse()

    for(let i = 0; i < points.length; i += 2) {
        //或者使用构造函数
        // const point = new DOMPoint(points[i], points[i+1])
        const point = DOMPoint.fromPoint({x: points[i], y: points[i + 1]})
        const transformedPoint = point.matrixTransform(matrix)
        output.push(transformedPoint.x, transformedPoint.y)
    }

    return output
}
```