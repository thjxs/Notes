# 检索结果

* 从数据表中获取所有行
`$users = DB::table('users')->get();`

* 从数据表中获取单行或列
// 获取整行
`$user = DB::table('users')->where('name', 'John')->first();`
// 获取单个值
`$email = DB::table('users')->where('name', 'John')->value('email');`
// 获取一列的值
// 单列值的集合
`$titles = DB::table('roles')->pluck('title');`
// 指定字段
`$roels = DB::table('roels')->pluck('title', 'name');`

* 分块结果
## 使用 `chunk` 方法可以从数千条需要处理的数据中取出一小块结果，并将结果传递给闭包处理
``` 
DB::table('users')->orderBy('id')->chunk(100, function ($users) {
	foreach($users as $user) {
		//
	}
});
```
通过在闭包中返回 `false` 来阻止分块结果

* 聚合
`count`, `max`, `min`, `avg`, `sum`

* 确定纪录是否存在
// exists() doesntExist();
`DB::table('orders')->where('finalized', 1)->exists();`

* 指定一个 select 语句
`$users = DB::table('users')->select('name', 'email as user_email')->get();`

* distinct 强制让查询返回不重复的结果
`$users = DB::table('users')->distinct()->get();`

* addSelect() 在现有的 select 语句加入一个字段
```
$query = DB::table('users')->select('name');
$users = $query->addSelect('age')->get();
```