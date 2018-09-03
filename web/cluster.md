# Nginx load balancer 负载均衡集群

## method
* round-robin -- requests to the application servers are distributed in a round-robin fashion,
* least-connected -- next request is assigned to the server with the least number of active connections,
* ip-hash -- a hash-function is used to determine what server should be selected for the next request(based on the client's IP address)

# deploy
```
http {
    upstream backend {
        server 10.1.0.1 weight=2 max_fails=3 fail_timeout=3s;
        server 10.1.0.2 weight=5 max_fails=3 fail_timeout=3s;
        server 10.1.0.3 weight=3 max_fails=3 fail_timeout=3s;
    }

    server {
        listen 80;
        location / {
            proxy_pass http://backend;
            proxy_next_upstream http_500 http_502 error timeout invalid_header;
            proxy_set_header Host $host;
            client_body_buffer_size: 100m;
        }
    }
}

```
