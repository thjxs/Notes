# HTTP headers

## Authentication

Contains the credentials to authenticate a user-agent with a server.

## Age

The time, in seconds, that the object has been in a proxy cache.

## Cache-Control

Directives for caching mechanisms in both requests and responses.

cache request directives

```text
Cache-Control: max-age=<seconds> // Expiration
Cache-Control: max-stale[=<seconds>]
Cache-Control: min-fresh=<seconds>
Cache-Control: no-cache // Cache but revalidate
Cache-Control: no-store // No caching
Cache-Control: no-transform
Cache-Control: only-if-cached
```

cache response directives

```text
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

```text
Content-Disposition: inline
Content-Disposition: attachment
Content-Disposition: attachment; filename="filename.jpg"
```

## Set-Cookie

```text
Set-Cookie cc=ee; Expires=Wed, 21 Oct 2015 07:28:00 GMT; Secure; HttpOnly
Set-Cookie: key=value; SameSite=Strict
```

## Cross-Origin Resource Sharing

A web application executes a cross-origin HTTP request when it requests a resource that has a different origin (domain, protocol, or port) from its own

### response headers

* Access-Control-Allow-Origin: *
* Access-Control-Expose-Headers: X-My-Custom-Header, X-Another-Custom-Header
* Access-Control-Max-Age: 3600
* Access-Control-Allow-Credentialed: true
* Access-Control-Allow-Methods: GET, POST
* Access-Control-Allow-Headers: Content-Type

### request headers

* Origin
* Access-Control-Request-Method
* Access-Control-Request-Headers

## Content negotiation

* Accept: text/html, application/json
* Accept-Charset: utf-8
* Accept-Encoding: gzip
* Accept-Language: de
