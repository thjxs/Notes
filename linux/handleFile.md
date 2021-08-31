# 逐行读取文件

```sh
#!/usr/bin/bash
file=$1
str="[\n"
while read line
do
    # test if line is empty
    if [ -z "$line" ]; then
        continue
    fi
    # do something
done < $file
str=$str"]"
# enable interpretation of backslash escapes
echo -e $str > output
```
