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

## execCommand
When an HTML document has been switched to `designMode`, its `document` object
exposes an `execCommand` method to run commands that manipulate the current 
editable region, such as form inputs or contentEditable elements.

Most commands affect the document's selection (bold, italics, etc.), while others 
insert new elements (adding a link), or affect an entire line (indenting). When
using `contentEditable`, `execCommand` affects the currently active editable element.

```js
document.execCommand(aCommandName, aShowDefaultUI, aValueArgument)
```

## queryCommandSupported
```js
document.queryCommandSupported('copy')
```
