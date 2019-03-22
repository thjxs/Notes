`Representational State Transfer`
使用 **URI** 定位资源，用 **HTTP** 动词描述操作

## 设计原则
1. HTTPS 

2. 域名
     与主域名分开  `https://api.larabbs.com` || `https://www.larabbs.com/api`

3. 版本控制
    ```
    # 将版本号加入 URL 中
    https://api.larabbs.com/v1
    https://api.larabbs.com/v2
    
    # 用 HTTP 请求头的 Accept 字段区分
    https://api.larabbs.com/
        Accept: application/prs.larabbs.v1+json
        Accept: application/prs.larabbs.v2+json
    ```

4. 用 URL 定位资源
    ```
    GET /issues
    GET /orgs/:org/issues
    GET /repos/:owner/:repo/issues/:number
    POST /repos/:owner/:repo/issues
    PATCH /repos/:owner/:repo/issues/:number
    PUT /repos/:owner/:repo/issues/:number/lock
    DELETE /repos/:owner/:repo/issues/:number/lock
    ```

5. 用 HTTP 动词描述操作

  动词通常就是五种 HTTP 方法（GET, POST, PUT, PATCH, DELETE, 一律为大写），对应 CURD 操作，幂等性 指一次和多次请求一个资源应该有同样的副作用

6. 资源过滤
    ```
    ?state=closed
    ?page=2&per_page=100
    ?sortby=name&order=asc
    ```

7. 状态码
    ```
    200 OK
    201 Created
    202 Accepted
    204 No Content
    304 Not Modified
    400 Bad Request
    401 Unauthorized
    403 Forbidden
    404 Not Found
    405 Method Not Allowed
    410 Gone
    415 Unsupported Media Type
    422 Unprocessable Entity
    429 Too Many Requests
    ```
