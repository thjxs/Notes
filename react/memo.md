# memo - higher order component

memo only checks for prop changes

be care of compare

## why memo brings performance boost
it will reuse last rendered result

## tips
Instead of forwardRef(memo(...)), use memo(forwardRef(...))
