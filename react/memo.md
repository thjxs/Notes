# memo - higher order component

memo only checks for prop changes, if `prevProps` equal `nextProps` and `current.ref` equal `workInProgress.ref`, it will reuse last rendered result, which brings performance boost

be care of compare, default `shallowEaul`, may provide `compare` function

there are two type of memo
* SimpleMemoComponent
* MemoComponent

## tips
Instead of forwardRef(memo(...)), use memo(forwardRef(...))
