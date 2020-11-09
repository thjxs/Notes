## mocha config file
```yml
# .mocharc.yml
reporter : spec
ui : bdd
timeout : 7000
slow : 200
```

## ES6 
update mocha config (`.mocharc.yml`)
```yml
require:
  - '@babel/register'
```

update babel config(`babel.config.json`)
```json
{
    "presets": ["@babel/preset-env"]
}
```

Add packages
```
yarn add @babel/core @babel/preset-env @babel/register
```
