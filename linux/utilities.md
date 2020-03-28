## tr
小写 => 大写  ` tr [a-z] [A-Z]`

删除 Windows '^M' 字符 `tr -d "\r"`

#### 压缩重复字符
```
​    1,,2,,,3,,,

`tr -s , < stdin`

`>> 1,2,3,`
```

## insert
```sh
#!/usr/bin/bash
str=''
for c in {A..Z}
do
    str+="'${c}',"
done

sed -i 29i"${str}" ./lib/helpers.js
```

## find mv
```sh
#!/usr/bin/bash
# find all mp4 file then move them to current directory
find ./ -name '*.mp4' -exec mv {} ./ \;
```
