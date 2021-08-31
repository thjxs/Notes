# Classes

## Inheritance

```js
class A {
    echo() {
        console.log('eee')
    }
}

class Aa extends A {
    echo() {
        super.echo()
    }
}
```

## Public, private, and protected modifiers

```ts
class A {
    public name: string;
    private age: number;
    protected weight: number;
}
```

### ECMAScript

```js
// private fields
class A {
    #name = 'xx'
}
```

## Accessors

```js
class A {
    get name() {
        return this.#name
    }

    set name(name) {
        this.#name = name
    }
}
```

## Static Properties
