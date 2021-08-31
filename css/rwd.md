# some rules about responsive web design

* Don't set breakpoints to popular device widths

## Responsive images

* srcset

```html
<img src="scones_small.jpg" srcset="scones_medium.jpg 1.5x, scones_large.jpg 2x">

<img 
src="scones-small.jpg 450w, scones-medium.jpg 900w" 
size="(min-width: 17em) 100vw, (min-width: 40em) 50vw" 
src="scones-small.jpg">
```

## CSS3

* The anatomy of a CSS rule (what defines a rule, declaration and property, and value pairs)
* Quick and handy CSS triicks for responsive designs (multiple columns, word wraps, truncation/text ellipsis, scrolling areas)
* Facilitating feature forks in CSS (how to have some rules apply to some browsers and other rules apply to others)
* How to use sub-string attribute selectors to select HTML elements
* What nth-based selectors are and how we can use them.
* What pseudo classes and pseudo elements are (:empty, ::before, ::after, :target, :scope)
* The new selectors in CSS Level 4 Selectors module(:has)
* What CSS variables and custom properties are and how to write them
* What the CSS *calc* function is and how to use it
* Making use of viewport related units (vh, vw, vmin, and vmax)
* How to make use of web typography with @font-face
* RGB and HSL color modes with Alpha transparency
