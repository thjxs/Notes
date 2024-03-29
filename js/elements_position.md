# 属性

* clientHeight & clientWidth
 指元素的内容部分加上 padding 占据的视觉面积
* scrollHeight & scrollWidth
 包含滚动条在内的该元素的视觉面积

## 获取网页元素的绝对位置

网页元素的绝对位置，指该元素的左上角相对于整张网页左上角的坐标。

```js
function getElementLeft(element) {
 let actualLeft = element.offsetLeft;
 let current = element.offsetParent;

 while(current !== null) {
  actualLeft += current.offsetLeft;
  current = current.offsetParent;
 }

 return actualLeft;
}

function getElementTop(element) {
 let actualTop = element.offsetTop;
 let current = element.offsetParent;

 while(current !== null) {
  actualTop += current.offsetTop;
  current = current.offsetParent;
 }

 return actualTop;
}
```

## 获取元素的相对位置

指元素左上角想对于浏览器窗口左上角的坐标

```js
function getElementViewLeft(element) {
 let actualLeft = element.offsetLeft;
 let current = element.offsetParent;

 while (current !== null) {
  actualLeft += current.offsetLeft;
  current = current.offsetParent;
 }

 let elementScrollLeft = document.documentElement.scrollLeft;  
 if (document.compatMode == "BackCompat") {
  elementScrollLeft = document.body.scrollLeft;
 }

 return actualLeft - elementScrollLeft;
}

function getElementViewTop(element) {
    let actualTop = element.offsetTop
    let current = element.offsetParent

    while (current !== null) {
        actualTop += current.offsetTop
        current = current.offsetParent
    }

    let elementScrollTop = document.documentElement.scrollTop
    if (document.compatMode === 'BackCompat') {
        elementScrollTop = document.body.scrollTop
    }
    return actualTop - elementScrollTop
}


```
