# drop

The **`drop`** event is fired when an element or text selection is dropped on a valid
drop target.

```html
<div id='droptarget'></div>
```

```js
const droptarget = document.getElementById('droptarget');
droptarget.ondragover = function(e) {
    e.preventDefault();
}
droptarget.ondrop = function(e) {
    const files = e.dataTransfer.files;
    for(let i = 0; i < files.length; i += 1) {
        let type = files[i].type;
        if (type.substring(0, 6) !== 'image/') {
            continue;
        }
        const img = document.createElement('img');
        img.src = URL.createObjectURL(files[i]);
        img.onload = function() {
            this.width = 300;
            document.body.appendChild(this);
            URL.revokeObjectURL(this.src);
        }
    }
    e.preventDefault();
}
```

## example

```html
<div class='dropzone'>
    <div id='draggable' draggable='true' ondragstart="event.dataTransfer.setData('text/plain', null)">
        This is a draggable
    </div>
</div>
<div class='dropzone'></div>
<div class='dropzone'></div>
<div class='dropzone'></div>
<style>
#draggable {
    wdith: 200px;
    height: 20px;
    text-align: center;
    background: white;
}
.dropzone {
    width: 200px;
    height: 20px;
    background: yellow;
}
</style>
```

```js
var dragged;
document.addEventListener('drag', function (e) {}, false);
document.addEventListener('dragstart', function (e) {
    dragged = e.target;
    e.target.style.opacity = .5;
    e.target.style.color = 'red';
}, false);
document.addEventListener('dragend', function (e) {
    e.target.style.opacity = '';
}, false);
document.addEventListener('dragover', function (e) {
    e.preventDefault();
}, false);
document.addEventListener('dragenter', function (e) {
    if (e.target.className == 'dropzone') {
        e.target.style.background = 'purple';
    }
}, false);
document.addEventListener('dragleave', function (e) {
    if (e.target.className == 'dropzone') {
        e.target.style.background = '';
    }
}, false);
document.addEventListener('drop', function (e) {
    e.preventDefault();
    if (e.target.className == 'dropzone') {
        e.target.style.background = '';
        dragged.parentNode.removeChild(dragged);
        e.target.appendChild(dragged);
    }
}, false);
```
