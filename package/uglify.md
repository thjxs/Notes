## UglifyJS 3

[UglifyJS](https://github.com/mishoo/UglifyJS) is a JavaScript parser, minifier, compressor and beautifier toolkit.

## Install
```bash
yarn add uglify-js
```

## Reference
```js
const uglifyJS = require('uglify-js')
const code = 'function add(f,s) {    return f + s;    }'
const result = uglifyJS.minify(code)
console.log(result.error)
console.log(result.code)
```
