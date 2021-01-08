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
