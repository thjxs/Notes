# [transform](https://developer.mozilla.org/zh-CN/docs/Web/CSS/transform) 修改 css 视觉格式模型的坐标空间 （只对块级元素生效）

translate rotate scale skew

常见的坐标系统：笛卡尔坐标系统和齐次坐标。

## matrix

`matrix(a, b, c, d, tx, ty)` 用六个指定的值来指定一个均匀的二维变换矩阵

## rotate

从原点（由 transform-origin 属性指定）按顺时针旋转特定角度

transform 可以用多个变换函数，比如 `rotate` `translate` 的先后顺序会出现不一致的效果。

## transform-origin  转换的起始位置

```css
transform-origin: center bottom;
```
