# interactive [prompts](https://github.com/terkelg/prompts)

## usage

```js
const prompts = require('prompts');

(async () => {
    const response = await prompts({
        type: 'number',
        name: 'age',
        message: 'How old are you?',
        validate: value => value < 18 ? `Nightclub is 18+ only` : true
    })

    console.log(response) // eg: {age: 24}
})();
```
