## start up
定义一个 *clipboard-copy* 标签
用 navigator.clipboard 或 Selection 和 Range 复制内容到剪切板

### reminder
* dispatchEvent
* CustomEvent
* ownerDocument
* navigator.clipboard

##  custom element
```js
import ClipboardCopyElement from './clipboard-copy-element'

if (!window.customElements.get('clipboard-copy')) {
  window.ClipboardCopyElement = ClipboardCopyElement
  window.customElements.define('clipboard-copy', ClipboardCopyElement)
}
```

## element
```js
import {copyInput, copyNode, copyText} from './clipboard'

function copy(button: HTMLElement) {
    const id = button.getAttribute('for')
    const text = button.getAttribute('value')

    function trigger() {
        button.dispatchEvent(new CustomEvent('clipboard-copy', {bubbles: true}))
    }

    if (text) {
        copyText(text).then(trigger)
    } else if (id) {
        const node = button.ownerDocument.getElementById(id)
        if (node) copyTarget(node).then(trigger)
    }
}

function copyTarget(content: Element) {
    if (content instanceof HTMLInputElement || content instanceof HTMLTextAreaElement) {
        if (content.type === 'hidden') {
            return copyText(content.value)
        } else {
            return copyInput(content)
        }
    } else if (content instanceof HTMLAnchorElement && content.hasAttribute('href')) {
        return copyText(content.href)
    } else {
        return copyNode(content)
    }
}

function clicked(event: MouseEvent) {
    const button = event.currentTarget
    if (button instanceof HTMLElement) {
        copy(button)
    }
}

function keydown(event: KeyboardEvent) {
    if (event.key === ' ' || event.key === 'Enter') {
        content button = event.currentTarget
        if (button instanceof HTMLElement) {
            event.preventDefault()
            copy(button)
        }
    }
}

function focused(event: FocusEvent) {
    event.currentTarget.addEventListener('keydown', keydown)
}

function blurred(event: FocusEvent) {
    event.currentTarget.removeEventListener('keydown', keydown)
}

export default class ClipboardCopyElement extends HTMLElement {
    constructor() {
        super()
        this.addEventListener('click', clicked)
        this.addEventListener('focus', focused)
        this.addEventListener('blur', blurred)
    }

    connectedCallback() {
        if (!this.hasAttribute('tabindex')) {
            this.setAttribute('tabindex', '0')
        }

        if (!this.hasAttribute('role')) {
            this.setAttribute('role', 'button')
        }
    }

    get value(): string {
        return this.getAttribute('value') || ''
    }

    set value(text: string) {
        this.setAttribute('value', text)
    }
}
```

## clipboard
```js
function createNode(text: string): Element {
    const node = document.createElement('pre')
    node.style.width = '1px'
    node.style.height = '1px'
    node.style.position = 'fixed'
    node.style.top = '5px'
    node.textContent = text
    return node
}

export function copyNode(node: Element): Promise<void> {
    if ('clipboard' in navigator) {
        return navigator.clipboard.writeText(node.textContent)
    }

    const selection = getSelection()
    if (selection === null) {
        return Promise.reject(new Error())
    }

    selection.removeAllRanges()

    const range = document.createRange()
    range.selectNodeContents(node)
    selection.addRange(range)

    document.execCommand('copy')
    selection.removeAllRanges()
    return Promise.resolve()
}

export function copyText(text: string): Promise<void> {
    if ('clipboard' in navigator) {
        return navigator.clipboard.writeText(text)
    }

    const body = document.body
    if (!body) {
        return Promise.reject(new Error())
    }

    const node = createNode(text)
    body.appendChild(node)
    copyNode(node)
    body.removeChild(node)
    return Promise.resolve()
}

export function copyInput(node: HTMLInputElement | HTMLTextAreaElement): Promise<void> {
    if ('clipboard' in navigator) {
        return navigator.clipboard.writeText(node.value)
    }

    node.select()
    document.execCommand('copy')
    const selection = getSelection()
    if (selection !== null) {
        selection.removeAllRanges()
    }
    return Promise.resolve()
}
```
