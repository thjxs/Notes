## innerHTML
```
document.getElementById('id').innerHTML = data.map(item => {
    return (
        '<li class="row"' +
            `<img src="${item.url}" />` +
            `<div>` +
                `<strong>${item.name}</strong>` +
            `</div>` +
        '</li>'
    )
}).join('');
```
