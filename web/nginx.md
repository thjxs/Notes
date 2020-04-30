## limiting bandwidth
```
location /download/ {
    limit_rate_after 500K;
    limit_rate 50K;
}
```
