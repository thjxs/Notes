# 类型转换

## 强制类型转换

> 强制类型转换总是返回标量基本类型值

### To string

* null => 'null'
* undefined => 'undefined'
* true => 'true'
* object => '[object Object]'
* [1,2,3] => '1,2,3' // 将所有单元字符串化以后再用 `,` 连接起来

### JSON 字符串化

不安全的 JSON 值：`undefined`, `function`, `symbol` 和循环引用

1. 字符串，数字，布尔值和 null 的 `JSON.stringify(..)` 规则与 `toString` 基本相同。
2. 如果传递给 `JSON.stringify(..)` 的对象定义了 `toJSON()` 方法，那么该方法会在字符串化前调用，以便将对象转换为安全的 `JSON` 值。

### To number

* true => 1
* false => 0
* undefined => NaN
* null => 0

字符串的处理遵循数字常量的相关规则。处理失败会返回 `NaN`

对象（包括数组）首先转换成相应的基本类型值，如果是非数字的基本类型值，则再遵循以上规则强制转换为数字。检查该值是否有 `valueOf()` 方法。 如果有并且返回基本类型值，就使用该值进行强制类型转换。如果没有就使用 `toString()` 的返回值（如果存在）来进行强制类型转换。

### To boolean

#### 假值(falsy value)

* undefined
* null
* false
* +0, -0, NaN
* ''
