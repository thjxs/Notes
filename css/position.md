# Position

## fixed

The element is removed from the normal documnet flow, and no space is created for the element in the page layout. It is positioned relative to the initial containing block established by the viewport, except when one of its ancestors has a `transform`, `perspective`, or `filter` property set to something other than `none`, or the `will-change` property is set to `transform`, in which case that ancestor behaves as the containing block. (Note that there are browser inconsistencies with `perspective` and `filter` contributing to containing block formation.) Its final position is determined by the values of `top`, `right`, `bottom`, and `left`.

The value always create a new `stacking context`. In printed documents, the element is placed in the same position on every page.

## sticky

> [https://dev.to/vinceumo/slide-stacking-effect-using-position-sticky-91f](https://dev.to/vinceumo/slide-stacking-effect-using-position-sticky-91f)

The element is positioned according to the normal flow of the document, and then offset relative to its nearest scrolling ancestor and containing block, including table-related elements, based on the values of `top`, `right`, `bottom` and `left`.
The offset does not affect he position of any other elements.

```text
position: sticky;
top: 20px;
```
