# example

```json
{
    "server": "npm start --prefix backend",
    "dev": "concurrently \"npm run server\" \"npm run start\""
}
```

concurrently -n \"Webpack,TypeScript Compiler\" -c \"cyan.bold,blue.bold\" \"webpack -w\" \"tsc --pretty --watch --preserveWatchOutput\" -k
