## using https
server {
    listen 80;
    server_name xxx.xxx;
    return 301 https://$host$request_uri;
}
