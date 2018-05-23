* 启动调度器

// 为当前用户创建一个 cron 服务
`crontab -e` 

// 添加如下内容
```
// m h dom mon dow command
* * * * * php /path-to-your-project/artisan schedule:run >> /dev/null 2>&1
```
//该 cron 会每分钟调用一次 `php artisan schedule:run` , 此时 Laravel 会根据调度执行预定任务

> Note: 命令的路径需要使用绝对路径

> tips: 
crontab 符合的含义
'\*' 代表取值范围内的数字
'-' 代表某个区间 如: 1-3
'/' 代表每
',' 代表离散的数字 如: 1,3,6
crontab 的一些写法
30 21 * * * command    | 每天21:30 执行
30 21 5,15,25 * * command | 每月的5，15，25日执行
0 23-7/1 * * * command | 晚上11点至早上7点，每小时执行

* 定义调度

Laravel 可以定义四种不同类型的调度任务: Closure command job exec. 
这里使用了 command
1. 在 `App\Console\Kernel` 的 schedule 方法里定义调度任务

```
.
.
.
protected function schedule(Schedule $schedule)
{
	// 每分钟执行执行一次 ehoc:string
	$schedule->command('echo:string')->everyMinute()->withoutOverlapping();
}

```

2. 创建 Artisan 命令
` php artisan make:command EchoString --command=echo:string `

接着在 `app/Console/Commands/EchoString.php` handle 方法里添加代码
```
.
.
.
class EchoString extends Command
{
	// 在定义任务调度时使用了该签名
	protected $signature = 'echo:string';

	protected $description = 'echo string';

	public function handle()
	{
		// 在 storage/logs/laravel.log 输出信息
		\Log::info('cron test');
	}
}
```
* 其它

1.  查看 crontab 服务
crontab -l

2. 查看 cron 服务
pgrep cron