# Usage

## 非负整数

```text
^\d+$
```

## 以字母，下划线开头的 8-10 位字符

```text
^[\w_]\w{8,10}$
```

## 替换

```text
/<p>\s?(<img.*?>)\s*<\/p>/s   <div>$1</div>    # $1 => <img.*?>
```

## ascii 匹配所有 ASCII 非可视字符

```text
[^\x20-\x7E]
```

## 修正数字

* 保留小数点后两位，如果第三位不为零，也需要保留
`(\.\d\d[1-9]?)\d*`

## 顺序环视

* 将 Jeffs 替换为 Jeff's
`/\bJeff(?=s\b)/Jeff's/g`

## 匹配数字

`[0-9][0-9]*$`

## 匹配数字和字母混合

`^(?![0-9]{5}$)(?![A-z]{5}$)[0-9A-z]{5}$`

## Backreferences

`/([abc])\1\1/g`

* abc // no match
* aaa // matched
* bbb // matched

`/[abc][abc][abc]/g`

* abc // mathced
* bac // matched
* a cbale // matched

## Query string parameters

`/^\?(\w+)=(\w+)(?:&(\w+)=(\w+))*$/g`

## file extension

`/\.[^./\\]*$/`
