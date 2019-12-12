## handle file

```js
const fs = require('fs')
// read argv from cli
let path = process.argv[2]

// path, options, callback
fs.readFile(path, 'utf8', (err, data) => {
    if (err) throw err;
    createJson(data)
})

function createJson(dataSource) {
    let data = dataSource.split('\n')
    let string = ''
    for (let i = 0; i < data.length; i += 1) {
        if (data[i] === '') continue;
        // format
        string += `
    {
        title: '${data[i]}',
        dataIndex: 'reserved',
        key: 'reserved'
    },`
    }
    string = '[' + string + '\n]'
    fs.writeFile('test', string, (err) => {
        if (err) throw err;
        console.log('done')
    })
}
```
