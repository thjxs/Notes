## Autologin with Laravel 5.6 

这是 laravel 5.6 的新特性，signed urls。
使用自带签名认证的url可以实现url自动登录，并不需要依赖数据的存储

```
#创建路由

use App\User;
use Illuminate\Support\Facades\Auth;

Route::get('/autologin/{user}', function (User $user) {
  Auth::login($user);

  return redirect()->home();
})->name('autologin')->middleware('signed');
```

```
# 生成url

use App\User;
use Illuminate\Support\Facades\URL;

$user = User::first();

$url = URL::signedRoute('autologin', ['user' => $user]);
```

```
#设置有效期

use App\User;
use Illuminate\Support\Facades\URL;

$user = User::first();

$url = URL::temporarySignedRoute(
  'autologin',
  now()->addDays(1),
  ['user' => $user]
);
```

```
# 定义异常处理
# App\Exceptions\Handler

public function render($request, Exception $exception)
{
    if ($exception instanceof \Illuminate\Routing\Exceptions\InvalidSignatureException) {
        return response()->view('home');
    }
    return parent::render($request, $exception);
}
```