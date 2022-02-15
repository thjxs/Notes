# DOM

## DOMHighResTimeStamp

The value of a `DOMHighResTimeStamp` is a double-precision floating-point number which describes the number of milliseconds (accurate to within 5 microseconds if the device supports it) elapsed between two points in time. The starting time can be either a specific time determined by the script for a site or app, or the time origin.

## innerHTML

```js
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

## getComputedStyle

```js
const getStyle = (el, ruleName)  => getComputedStyle(el)[ruleName];

getStyle(document.body, 'font-size'); // '16px'
```

## hasClass

```js
const hasClass = (el, className) => el.classList.contains(className);

hasClass(document.querySelector('p.special'), 'special');
```

## getElementsByClassName

elements is a live `HTMLCollection` of found elements

## querySelectorAll

returns a static (not live) `NodeList`
