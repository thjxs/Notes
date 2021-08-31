# Inter Process Communication

Electron 有多个渲染进程和一个主进程

```js
// main process

ipcMain.on('msg', (ev, arg) => {
    ev.reply('msg', 'pong')
})

// renderer process
ipcRenderer.on('msg', (ev, arg) => {
    //
})
```

## multiple renderer process

```js
// main
let w1, w2
let u1, u2
ipcMain.on(u1, () => {
    // do some thing with w1
})

ipcMain.on(u2, () => {
    // do some thing with w2
})

// process 1
ipcRenderer.on('init', (uid) => {
    ipcRenderer.on(uid, listener)
})
ipcRenderer.send(uid, {ev, data})
// process 2
```
