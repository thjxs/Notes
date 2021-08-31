# handle file

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

## write stream

```js
const fs = require('fs')
const request = require('request')
const http = require('http')
const url = 'http://www.joshuawright.net/images/picture%20-%20slackwyrm%20003a.jpg?crc=3994258789'

http.get(url, (res) => {
    const imgWriteStream = fs.createWriteStream('a.png')
    res.on('data', function(chunk) {
        imgWriteStream.write(chunk)
    })
    res.on('end', function (e) {
        imgWriteStream.end()
    })
})

const req = request(url).pipe(fs.createWriteStream('b.png'))
req.on('end', () => {
    console.log('???')
})
```
