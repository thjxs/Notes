## Authentication
Contains the credentials to authenticate a user-agent with a server.

## Age
The time, in seconds, that the object has been in a proxy cache.

## Cache-Control
Directives for caching mechanisms in both requests and responses.

cache request directives
```
Cache-Control: max-age=<seconds> // Expiration
Cache-Control: max-stale[=<seconds>]
Cache-Control: min-fresh=<seconds>
Cache-Control: no-cache // Cache but revalidate
Cache-Control: no-store // No caching
Cache-Control: no-transform
Cache-Control: only-if-cached
```

cache response directives
```
Cache-Control: must-revalidate
Cache-Control: no-cache
Cache-Control: no-store
Cache-Control: no-transform
Cache-Control: public
Cache-Control: private
Cache-Control: proxy-revalidate
Cache-Control: max-age=<seconds>
Cache-Control: s-maxage=<seconds>
```

## Content-Disposition

```
Content-Disposition: inline
Content-Disposition: attachment
Content-Disposition: attachment; filename="filename.jpg"
```

## Set-Cookie
```
Set-Cookie cc=ee; Expires=Wed, 21 Oct 2015 07:28:00 GMT; Secure; HttpOnly
Set-Cookie: key=value; SameSite=Strict
```
