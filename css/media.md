# 媒体查询的分界点

超小屏幕 手机 less than 768px

小屏幕 平板 >=768px

中等屏幕 992px

大屏幕 1200px

# media query syntax
@media not|only mediatype and (expressions) {
	//css
}

# media type
all print screen speech

# 图片
设置 *max-width* 图片不会大于其原始大小

# demo
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

# media queries in link tags
<link rel="stylesheet" type="text/css" href="style.css" media="screen">
<link rel="stylesheet" type="text/css" href="style.css" media="screen and (orientation: portrait)">

# Combining media queries
<link rel="stylesheet" type="text/css" href="#" media="screen and (orientation: portrait) and (min-width: 800px)">

# Media queries with @import
@import url ("phone.css") screen and (max-width: 360px);

# Media queries in CSS
@media screen and (max-device-width: 400px)

# Scripting media feature
@media (scripting: none) { ... }
@media (scripting: enabled) { ... }
```

# Interaction media features
# The hover media feature
# Environment media features
