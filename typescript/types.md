# Types

## Ref

```text
ref: React.RefObject<HTMLInputElement> = React.createRef()
```

## Event

```text
onChange = (e: React.ChangeEvent<HTMLTextAreaElement>) => {}
```

## User-Defined Type Guards

```typescript
function isFish(pet: Fish | Bird): pet is Fish {
    return (pet as Fish).swim !== undefined
}

let pet = getSmallPet()
if (isFish(pet)) {
    pet.swim()
} else {
    pet.fly()
}
```

## Index types and index signatures

```typescript
interface Dictionary<T> {
    [key: string]: T
}

let keys: keyof Dictionary<number>
// keys: string | number
// If you have a type with a number index signature, keyof T will just be number.
let value: Dictionary<number>['foo']
// value: number
```

## Conditional Types

type relationship test: **T extends U ? X : Y**
T is assignable to U the type is X, otherwise the type is Y

```typescript
declare function f<T extends boolean>(x: T): T extends true ? string : number

let x = f(Math.random() < 0.5)
```
