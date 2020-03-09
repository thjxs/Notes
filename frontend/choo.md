## require
choo: framework

webpack: build tool

webpack-cli: as

tailwindcss: css framework

copy-webpack-plugin: copy files

css-loader: css loader module for webpack

cssnano: a modular minifier, built on top of the postcss ecosystem

html-webpack-plugin: Simplifies creation of HTML files to serve your webpack bundles

mini-css-extract-plugin: extracts css into separate files

postcss-loader: postcss-loader for webpack


## webpack config
output
```js
output: {
    chunkFilename: '[name].[contenthash:8].js', // eg: app.490e66b3.js
    filename: '[name].[contenthash:8].js',
    path: path.resolve(__dirname, 'dist')
}
```

module
```js
module: {
    rules: [
        {
            test: /\.js$/,
            exclude: /node_modules/,
            use: {
                loader: 'babel-loader',
                options: {
                    presets: ['@babel/preset-env']
                }
            }
        },
        {
            test: /\.css$/,
            use: [
                MiniCssExtractPlugin.loader, // extracts css file
                {
                    loader: 'css-loader',
                    options: {importLoaders: 1}
                },
                'postcss-loader'
            ]
        }
    ]
}
```

plugins
```js
plugins: [
    new HtmlWebpackPlugin(), // create index html file
    new MiniCssExtractPlugin({
        filename: '[name].[contenthash:8].css'
    })
]
```

## tailwind
```
@tailwind base;
@tailwind components;
@tailwind utilities;
```

## choo
[https://choo.io/](https://choo.io/)
