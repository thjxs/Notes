# Example

```js
const r180 = Math.PI
const r90 = Math.PI / 2
const r15 = Math.PI / 12
const color = '#88888825'

const canvas = document.createElement('canvas')

document.body.appendChild(canvas)

const ctx = canvas.getContext('2d')

const dpr = window.devicePixelRatio || 1

const bsr = ctx.webkitBackingStorePixelRatio || ctx.mozBackingStorePixelRatio || ctx.msBackingStorePixelRatio || ctx.oBackingStorePixelRatio || ctx.backingStorePixelRatio || 1

const dpi = dpr / bsr

canvas.style.width = '520px'
canvas.style.height = '520px'

canvas.width = dpi * 520
canvas.height = dpi * 520

ctx.scale(dpi, dpi)

function polar2cart(x=0, y=0, r=0,theta=0) {
    const dx = r * Math.cos(theta)
    const dy = r * Math.sin(theta)
    return [x + dx, y + dy]
}

let steps = []
let prevSteps = []
let iterations = 0

const step = (x, y, rad) => {
    const length = Math.random() * 6
    const [nx, ny] = polar2cart(x, y, length, rad)
    ctx.beginPath()
    ctx.moveTo(x, y)
    ctx.lineTo(nx, ny)
    ctx.stroke()
    const rad1 = rad + Math.random() * r15
    const rad2 = rad - Math.random() * r15
    if (nx < -100 || nx > 600 || ny < -100 || ny > 600) {
        return
    }
    if (iterations <= 4 || Math.random() > 0.5) {
        steps.push(() => step(nx, ny, rad1))
    }
    if (iterations <= 4 || Math.random() > 0.5) {
        steps.push(() => step(nx, ny, rad2))
    }
}

let lastTime = performance.now()

const interval = 1000 / 4

const frame = () => {
    if (performance.now() - lastTime < interval) {
        return
    }
    iterations += 1
    prevSteps = steps
    steps = []
    lastTime = performance.now()

    prevSteps.forEach(i => i())
}

ctx.clearRect(0, 0, 520, 520)

ctx.lineWidth = 1

ctx.strokeStyle = color

prevSteps = []

steps = [
    () => step(Math.random() * 520, 0, r90),
    () => step(Math.random() * 520, 520, -r90),
    () => step(0, Math.random() * 520, 0),
    () => step(520, Math.random() * 520, r180),
]

function loop() {
    frame()
    requestAnimationFrame(loop)
}

loop()

```
