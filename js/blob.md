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

// async
async function saveFile(file) {
    return new Promise(function (resolve, reject) {
        const dataView = new DataView(file.plaintext)
        const blob = new Blob([dataView], {type: file.type})
        if (navigator.msSaveBlob) {
            navigator.msSaveBlob(blob, file.name)
            return resolve()
        } else if (/iPhone|fxios/i.test(navigator.userAgent)) {
            const reader = new FileReader()
            reader.addEventListener('loadend', function () {
                if (reader.error) {
                    return reject(reader.error)
                }
                if (reader.result) {
                    const a = document.createElement('a')
                    a.href = reader.result
                    a.download = file.name
                    document.body.appendChild(a)
                    a.click()
                }
                resolve()
            })
            reader.readAsDataURL(blob)
        } else {
            const downloadUrl = URL.createObjectURL(blob)
            const a = document.createElement('a')
            a.href = downloadUrl
            a.download = file.name
            document.body.appendChild(a)
            a.click()
            URL.revokeObjectURL(downloadUrl)
            setTimeout(resolve, 100)
        }
    })
}
```
