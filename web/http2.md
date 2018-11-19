# Nginx
```
server {
    server_name domain.com
    listen 443 ssl http2 default_server;
    root /var/www/html;
    index index.html;

    location / {
        try_files $uri $uri/=404;
    }

    ssl_certificate     /etc/nginx/ssl/domain.com.crt;
    ssl_certificate_key /etc/nginx/ssl/domain.com.key;
}

server {
    listen 80;
    server_name domain.com;
    return 301 https://$server_name$request_uri;
}
```
