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
