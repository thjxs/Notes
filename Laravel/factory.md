## Factories

create 10 users and attach a relationship to each user

```php
factory(App\User::class, 10)->create()->each(function ($user) {
    $user->posts()->save(factory(App\Post::class)->make()); //saveMany also available
});
```

