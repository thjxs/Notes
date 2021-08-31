# Merging Interfaces

```typescript
interface Cloner {
    clone(n: number): number;
}
interface Cloner {
    clone(s: string): string
}

const cloner: Cloner = {
    clone<T>(arg: T) {
        return arg
    }
}
```
