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

# Selects

* 指定一个 select 语句
`$users = DB::table('users')->select('name', 'email as user_email')->get();`

* distinct 强制让查询返回不重复的结果
`$users = DB::table('users')->distinct()->get();`

* addSelect() 在现有的 select 语句加入一个字段
```
$query = DB::table('users')->select('name');
$users = $query->addSelect('age')->get();
```

# Joins

* Inner join
```
// ?
$users = DB::table('users')
			->join('contacts', 'users.id', '=', 'contacts.user_id')
			->join('orders', 'users.id', '=', 'orders.users_id')
			->select('users.*', 'contacts.phone', 'orders.price')
			->get();
```

* Left Join 
```
$users = DB::table('users')
			->leftJoin('posts', 'users.id', '=', 'posts.user_id')
			->get();
```

* Cross Join 
交叉连接在第一个表和连接之间生成笛卡儿积 // ？？？
```
$users = DB::table('users')
			->crossJoin('colours')
			->get();
```

* Advance Join
```
DB::table('users)
	->join('contacts', function ($join) {
		$join->on('users.id', '=', 'contacts.user_id')->orOn(...);
	})
	->get();
```

# Unions

把两个查询联合起来
```
$first = DB::table('users')
			->whereNull('first_name');

$users = DB::table('users')
			->whereNull('last_name')
			->union($first)
			->get();
```

# Where

查询构建器的 `where` 方法需要三个参数
列名 运算符 比较的值
`$users = DB::table('users')->where('votes', '=', 100)->get()`

```
$usres = DB::table('users')->where([
	['status', '=', '1'],
	['subscribed', '<>', '1'],
])->get();
```

* Or
```
$users = DB::table('users')
			->where('votes', '>', 199)
			->orWhere('name', 'John')
			->get();
```

* whereBetween
验证字段的值位于两个值之间

* whereNotBetween

* whereIn / whereNoIn

* whereNull / whereNotNull

* whereDate / whereMonth / whereDay / whereYear / whereTime

* whereColumn

* 参数分组
```
DB::table('users')
		->where('name', '=', 'John')
		->orWhere(function ($query) {
			$query->where('votes', '>', 100)
					->where('title', '<>', 'Admin');
		})
		->get();
// equal to select * from users where name = 'John' or (votes > 100 and title <> 'Admins')
```

* whereExists //???
```
DB::table('users')
		->whereExists(function ($query) {
			$query->select(DB::raw(1))
					->from('orders')
					->whereRaw('orders.user_id = users.id');
		})
		->get();
```

* JSON Where
```
$users = DB::table('users')
			->where('options->language', 'en')
			->get();

$users = DB::table('users')
			->where('preferences->dining->meal', 'salad')
			->get();
```

# Ordering, Grouping, Limit & Offset

* orderBy
```
$users = DB::table('users')
			->orderBy('name', 'desc')
			->get();
```

* latest / oldest

* inRandomOrder
```
$randomUser = DB::table('users')
				->inRandomOrder()
				->first();
```

* groupBy / having
```
$users = DB::table('users')
			->groupBy('account_id')
			->having('account_id', '>', 100)
			->get();
```

* skip / take
`DB::table('users')->skip(10)->take(5)->get();`
or
`DB::table('users')->offset(10)->limit(5)->get();`

# 条件语句
```
$role = $request->input('role');

$users = DB::table('users')
			->when($role, function ($query) use ($role) {
				return $query->where('role_id', $role);
			})
			->get();
```

一个查询的默认排序
```
$sortBy = null

$users = DB::table('users')
			->when($sortBy, function ($query) use ($sortBy) {
				return $query->orderBy($sortBy);
			}, function ($query) {
				return $query->orderBy('name');
			})
			->get();
```

# 插入

* insert
```
DB::table('users')->insert(
	['email' => 'john@example.com', 'votes' => 0]
);

```

* insertGetId
```
$id = DB::table('users')->insertGetId(
	['email' => 'john@example.com', 'votes' => 0]
);
```

# 更新

```
DB::table('users')
	->where('id', 1)
	->update(['votes' => 1]);

// JSON
DB::table('users')
	->where('id', 1)
	->update(['options->enabled' => 1]);
```

* 自增与自减
increment & decrement

# 删除
```
DB::table('users')->delete();
DB::table('users')->where('votes', '>', 100)->delete();
//清空表
DB::table('users')->truncate();
```

# 悲观锁
```
DB::table('users')->where('votes', '>', 100)->shareLock()->get();
DB::table('users')->where('votes', '>', 100)->lockForUpdate()->get();
```