# Meddia queries

## media query syntax

```css
@media not|only (media type) and (expressions) {
 //css
}
```

## media type

all print screen speech

## Media features

* any-hover
* any-pointer
* aspect-ratio
* color
* color-gamut
* color-index
* display-mode
* forced-colors
* grid
* height
* hover
* inverted-colors
* monochrome
* orientation
* overflow-block
* overflow-inline
* pointer
* prefers-color-scheme
* prefers-contrast
* prefers-reduced-motion
* resolution
* scripting
* update
* width

## dark mode

prefers-color-scheme: Detect if the user prefers a light or dark color scheme

```css
@media (prefers-color-scheme: dark) {
    body {
        background-color: #444;
        color: #e4e4e4;
    }
}
```

## hover

```css
button {

}

@media(hover: hover) {
    button {

    }
}

@media (hover: hover) and (pointer: fine) {
    button {

    }
}
```

## 媒体查询的分界点

超小屏幕 手机 less than 768px

小屏幕 平板 >=768px

中等屏幕 992px

大屏幕 1200px

## 图片

设置 *max-width* 图片不会大于其原始大小

## demo

```css
@media screen and (min-width: 480px) {
 body {
  background-color: lightgreen;
 }
}

@media screen and (min-width: 480px) {
 #leftsidebar { width: 200px; float: left; }
 #main { margin-left: 216px; }
}

// media queries in link tags
<link rel="stylesheet" type="text/css" href="style.css" media="screen">
<link rel="stylesheet" type="text/css" href="style.css" media="screen and (orientation: portrait)">

// Combining media queries
<link rel="stylesheet" type="text/css" href="#" media="screen and (orientation: portrait) and (min-width: 800px)">

// Media queries with @import
@import url ("phone.css") screen and (max-width: 360px);

// Media queries in CSS
@media screen and (max-device-width: 400px)

// Scripting media feature
@media (scripting: none) { ... }
@media (scripting: enabled) { ... }
```
