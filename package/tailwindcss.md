# tailwindcss
[Tailwind CSS](https://tailwindcss.com/docs/installation) works by scanning all of your HTML files, JavaScript components, and any other templates for class names, generating the corresponding styles and then writing them to a static CSS file.

It's fast, flexible, and reliable — with zero-runtime.

## install

```sh
npm install -D tailwindcss postcss autoprefixer

npx tailwindcss init -p
```

## config

```js
// tailwindcss.config.js
/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    "./src/**/*.{js,jsx,ts,tsx}",
  ],
  theme: {
    extend: {},
  },
  plugins: [],
}
```

```css
@tailwind base;
@tailwind components;
@tailwind utilities;
```

## plugins

* [line-clamp](https://github.com/tailwindlabs/tailwindcss-line-clamp)
