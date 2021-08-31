# html minifier

Highly configurable, well-tested, JavaScript-based HTML minifier.

## Install

```sh
yarn add html-minifier

yarn html-minifier --help
```

## Usage

```js
const minify = require('html-minifier').minify
const result = minify('<p title="usage" id="foo">content</p>', {
    removeAttributeQuotes: true
});

result; // '<p title=blah id=moo>foo</p>'

```
