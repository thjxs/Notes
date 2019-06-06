## 下载文件
```js
var downloadFn = function (content, filename, mime, bom) {
    var blobData = (typeof bom !== 'undefined') ? [bom, content] : [content];
    var blob = new Blob(blobData, {type: mime || 'application/octet-stream'});
    if (typeof window.navigator.msSaveBlob !== 'undefined') {
        window.navigator.msSaveBlob(blob, filename);
    } else {
        var blobURL = window.URL.createObjectURL(blob);
        var aLink = document.createElement('a');
        aLink.style.display = 'none';
        aLink.href = blobURL;
        aLink.setAttribute('download', filename); 

        // Safari
        if (typeof aLink.download === 'undefined') {
            aLink.setAttribute('target', '_blank');
        }

        document.body.appendChild(aLink);
        aLink.click();
        document.body.removeChild(aLink);
        window.URL.revokeObjectURL(blobURL);
    }
}
```
