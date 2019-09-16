## drop
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
