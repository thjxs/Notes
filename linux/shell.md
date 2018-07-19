## shell 重定向 &>file 2>&1 1>&2
```
文件描述符 
0 表示标准输入 
1 表示标准输出
2 表示标准错误输出
```
```
command >/dev/null 2>&1  # 将 1 重定向到 /dev/null, 再将 2 重定向到 1，两者都输出到 /dev/null
command 2>&1 >/dev/null  # 将 2 重定向到 1， 将 1 重定向到 /dev/null
```

## shell 字符串操作
```
${#string} # 字符长度
${string:position} # 从 $position 开始提取子串
${string:position:length} # 从 $position 开始，提取长度为 $length 的子串
${string#substring} # 从 $string 开头，删除最短匹配 $substring
${string##substring} # 从 $string 开头，删除最长匹配 $substring
${string%substring} # 从 $string 结尾开始，删除
${string%%substring} # ...
${string/substring/replacement} # 使用 replacement 替换第一个匹配的 substring
${string//substring/replacement} # 使用 replacement 替换所有的 substring
```
## sed 替换文本内容
```
sed -i 's/string/replacement/g' path/to/file
```
