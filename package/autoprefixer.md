## [autoprefixer](https://github.com/postcss/autoprefixer)
Parse CSS and add vendor prefixes to rules by [Can I Use](https://caniuse.com/)

## Grids in IE and autoprefixer

[Guide](https://css-tricks.com/css-grid-in-ie-css-grid-and-the-new-autoprefixer/)

由于不能100%可行，因此默认禁止。

将 `/* autoprefixer grid: autoplace */` 放在css文件顶部开启

## 配合 [browserlist](https://github.com/browserslist/browserslist#best-practices) 使用

`npx autoprefixer --info` 检查哪些属性将会被添加前缀
