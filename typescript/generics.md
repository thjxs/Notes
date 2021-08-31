# Generic Types

```typescript
// T: type variable
function identity<T>(arg: T): T {
    return arg;
}
```

```typescript
function loggingIdentity<T>(arg: T[]): T[] {
    console.log(arg.length)
    return arg
}
```

## Generic Constraints

```typescript
interface Lengthwise {
    length: number
}

function loggingIdentity<T extends Lengthwise>(arg: T): T {
    console.log(arg.length);
    return arg;
}

// no longer work over any and all types
loggingIdentity(3);
// Argument of type 'number' is not assignable to parameter of type 'Lengthwise'.

loggingIdentity({ length: 10, value: 3 });
```

## Using Type Parameters in Generic Constraints

```typescript
function getProperty<T, K extends keyof T>(obj: T, key: K) {
 return obj[key]
}
```
