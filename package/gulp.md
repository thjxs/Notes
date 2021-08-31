# gulp

A toolkit to automate & enhance your workflow

## build typescript

```js
const gulp = require('gulp')
const browserify = require('browserify')
const source = require('vinyl-source-stream')
const tsify = require('tsify')
const uglify = require('gulp-uglify')
const buffer = require('vinyl-buffer')

const option = {
    // browserify option
}
gulp.task('build', () => browserify(option) // require('modules') in the browser
    .plugin(tsify) // compiling typescript
    .bundle() // Bundle the files and their dependencies into a single javascript file. Return a readable stream
    .pipe(source('filename')) // Transform stream
    .pipe(buffer()) // Convert streaming vinyl files to use buffers.
    .pipe(uglify()) // Minify JavaScript with UglifyJS3.
    .pipe(gulp.dest('output')))

```

## change json file

```js
const gulp = require('gulp')
const {Transform} = require('stream')

function change() {
    return new Transform({
        objectMode: true,
        highWaterMark: 16,
        transform(chunk, encoding, callback) {
            const raw = chunk.contents.toString()
            const parsed = JSON.parse(raw)
            // do some thing with parsed

            chunk.contents = Buffer.from(JSON.stringify(parsed, null, 2))

            callback(null, chunk)
        }
    })
}

gulp.task('change', () => gulp.src('path/to/file')
    .pipe(change())
    .pipe(gulp.dest('output')))

```
