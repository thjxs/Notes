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
