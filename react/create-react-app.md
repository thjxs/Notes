# init
```sh
set -e
p=$1
yarn create react-app $p
cd $p
yarn add tailwindcss@npm:@tailwindcss/postcss7-compat @tailwindcss/postcss7-compat postcss@^7 autoprefixer@^9 @craco/craco

echo "module.exports = {
  style: {
    postcss: {
      plugins: [
        require('tailwindcss'),
        require('autoprefixer')
      ]
    }
  }
}

" >> craco.config.js

echo "module.exports = {
  purge: ['./src/**/*.{js,jsx,ts,tsx}', './public/index.html'],
  darkMode: false, // or 'media' or 'class'
  theme: {
    extend: {},
  },
  variants: {
    extend: {},
  },
  plugins: [],
}" >> tailwind.config.js

echo "@tailwind base;
@tailwind components;
@tailwind utilities;" >> src/index.css

```
