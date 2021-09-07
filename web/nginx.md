# nginx

## limiting bandwidth

```text
location /download/ {
    limit_rate_after 500K;
    limit_rate 50K;
}
```

## location

```text
location / {
    root /path/to/project_a;
    index index.html index.htm;
    try_files $uri $uri/ /;
}

location /another {
    alias /path/to/project_b;
    try_files $uri $uri/ /another;
}

```

### check if file exist

* -f file
* -d directory
* -e file or directory
* -x executable

```text
location / {
    if (!-f $request_filename) {
        rewrite ^(.*)$ /$1.html last;
        break;
    }
    index index.html;
}
```

## try_files

> [http://nginx.org/en/docs/http/ngx_http_core_module.html#try_files](http://nginx.org/en/docs/http/ngx_http_core_module.html#try_files)

Checks the existence of files in the specified order and uses the first found file for request processing.

```text
location / {
    index index.html;
    try_files $uri $uri/index.html $uri.html = 404;
}
```

Such as `/docs`, has following match.
* /docs
* /docs/index.html
* /docs.html
* 404
