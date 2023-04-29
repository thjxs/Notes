所有由css展示的元素都是一个盒子，不同的盒子受 `display` 的值，尺寸和内容（更多的盒子）影响。
盒子模型的几个区域

![img](/img/box-model.svg)

Content box，存放内容的区域。
Padding box，盒子的内边距，盒子的背景会在这个区域显示，如果存在滚动条，也会出现在这个区域。
Border box，围绕着盒子的内边距，用于呈现盒子的边框。
Margin box，盒子的外边距，`outline` 和 `box-shadow` 会在这个区域呈现。