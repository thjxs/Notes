# 创建 API Resource

> refs: [Eloquent-resources](https://laravel.com/docs/5.7/eloquent-resources)

## 编写资源

给定一个模型如 *User*

```php
$user->name = 'Foo';
$user->email = 'Bar@eamil.com';
$user->phone = '1xxxxxxxxxx';
```

返回的资源可以在 `App\Http\Resources\User`  *toArray*  方法里修改属性

```php
public function toArray($request)
{
    return [
        'name' => $this->name,
        'email' => $this->email,
    ];
}
```

同样地 `App\Http\Resources\UserCollection` 可以自定义 *collection* 的元数据

```php
public function toArray($request)
{
    return [
        'data' => $this->collection,
        'links' => [
            'self' => 'link-value',
        ],
    ];
}
```
