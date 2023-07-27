## With React

ref

```tsx
import { useRef, ElementRef } from 'react';
import BarComponent from './bar'

const Foo = () => {
	const ref = useRef<ElementRef<'div'>>(null);
	const barRef = useRef<ElementRef<typeof BarComponent>>(null)
	
	return (
		<div ref={ref}>
			<BarComponent ref={barRef} />
		</div>
	)
}
```
