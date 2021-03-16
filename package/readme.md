## Taobao
```
https://registry.npm.taobao.org
```

## Check registry
`yarn config get registry`

## Set registry
```
# tmp
yarn add electron --registry url
# static
yarn config set registry url
```

## Per package config
`yarn config set electron_mirror https://npm.taobao.org/mirrors/electron/`

## Check error
add `--verbos` flag

## publish
```
# login
npm login
# check registry
npm config get registry
# with scope (@thjxs/xx)
npm publish --access=publish
```

## workspaces
使用工作空间设置依赖
```json
{
    "private": true,
    "workspaces": [
        "packages/*"
    ]
}
```
## Set up homepage
```
package.json
"homepage": "."
```

## alias
为包设置别名
如 `yarn add tailwindcss@npm:@tailwindcss/postcss7-compat@*`
```json
{
  "dependencies": {
    "@tailwindcss/postcss7-compat": "^2.0.1",
    "tailwindcss": "npm:@tailwindcss/postcss7-compat",
  }
}
```

```js
// actual import @tailwindcss/postcss7-compat
const tailwindcss = require('tailwindcss')
```
