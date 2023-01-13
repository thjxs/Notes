# Collection

JavaScript package collection

## ulid

[https://github.com/ulid/javascript](https://github.com/ulid/javascript)

```js
import { ulid } from 'ulid'

ulid() // 01ARZ3NDEKTSV4RRFFQ69G5FAV
```

## recoil

[https://recoiljs.org/docs/introduction/installation/](https://recoiljs.org/docs/introduction/installation/)

A state management library for React.

Add recoil root
```jsx
<RecoilRoot>
...
</RecoilRoot>
```

Create a piece of state, then use it
```js
const state = atom({
    key: 'state',
    default: ''
})

const [value, setValue] = useRecoilState(state)
```

## blurhash

[https://github.com/woltapp/blurhash](https://github.com/woltapp/blurhash)

A very compact representation of a placeholder for an image.
