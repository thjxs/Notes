# Dependency injection
```php
interface SuperModuleInterface
{
    public function activate(array $target);
}

class XPower implements SuperModuleInterface
{
    public function activate(array $target)
    {
        //
    }
}

class Superman
{
    protected $ability;

    public function __construct(SuperModuleInterface $ability)
    {
        $this->ability = $ability;
    }
}

$superman = new Superman(new XPower);
```

# IoC
```php
class Container
{
    protected $binds;

    protected $instances;

    /**
     * Register a binds with the container
     *
     * @param string $abstract
     * @param \Closure|string $concrete
     * @return void
     */
    public function bind($abstract, $concrete)
    {
        if ($concrete instanceof Closure) {
            $this->binds[$abstract] = $concrete;
        } else {
            $this->instances[$abstract] = $concrete;
        }
    }

    /**
     * Resolve the give type from the container
     *
     * @param string $abstract
     * @param array $parameters
     * @return mixed
     */
    public function make($abstract, array $parameters = [])
    {
        if (isset($this->instances[$abstract])) {
            return $this->instances[$abstract];
        }

        array_unshift($parameters, $this);

        return call_user_func_array($this->binds[$abstract], $parameters);
    }
}
```

# example
```php
$container = new Container;
$container->bind('superman', function ($container, $ability) {
    return new Superman($container->make($ability));
});
$container->bind('xpower', function ($container) {
    return new XPower;
});

$superman = $container->make('superman', 'xpower');
```
