```js
const CACHE = 'cache-update-and-refresh'

self.addEventListener('install', function (evt) {
    evt.waitUntil(caches.open(CACHE).then(function (cache) {
        cache.addAll([
            './controlled.html', './asset'])
    }))
})

self.addEventListener('fetch', function (evt) {
    evt.respondWith(fromCache(evt.request))

    evt.waitUntil(update(evt.request).then(refresh))
})

async function fromCache(request) {
    const cache = await caches.open(CACHE)
    return cache.match(request)
}

async function update(request) {
    const cache = await caches.open(CACHE)
    const res = await fetch(request)
    return await cache.put(request, response.clone())
}

async function refresh(response) {
    const clients = await self.clients.matchAll()
    clients.forEach((client) => {
        const message = {
            type: 'refresh',
            url: response.url,
            eTag: response.headers.get('ETag')
        }

        client.postMessage(JSON.stringfy(message))
    })
}
```

