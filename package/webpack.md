# CONCEPTS

At its core, webpack is a static module bundler for modern JavaScript applications. When webpack processes your application, it internally builds a dependency graph which maps every module your project needs and generates one or more bundles.

## webpack-dev-server

Use webpack with a development server that provides live reloading.

## What I need

file-loader, json-loader, url-loader

## Resolving `import` at-rules

The `sass-loader` uses Sass's custom importer feature to pass all queries to the Webpack resolving engine. Thus you can import your Sass modules from node_modules. Just prepend them with a ~ to tell Webpack that this is not a relative import:

```text
@import '~bootstrap';
```
