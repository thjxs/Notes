## shell $ sign
```
$$
shell process ID
$!
shell background process ID
$?
exit code
$-
set flag
$*
arguments lists
$@
arguments lists
$#
num of arguments
$0
shell file name
$1 ~ $n
arguments value
```

## shell 重定向 &>file 2>&1 1>&2
```
文件描述符 
0 表示标准输入 
1 表示标准输出
2 表示标准错误输出
```
```sh
command >/dev/null 2>&1  # 将 1 重定向到 /dev/null, 再将 2 重定向到 1，两者都输出到 /dev/null
command 2>&1 >/dev/null  # 将 2 重定向到 1， 将 1 重定向到 /dev/null
```

## shell 字符串操作
```sh
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
```sh
sed -i 's/string/replacement/g' path/to/file
sed -i '/lines/s/targetstring/replacement/' path/to/file
# Example: delete the 4th line in a file
$ sed '4d' input.txt > output.txt
# Example: replace every occurrence of 'hello' with 'world' on lines 10-20
$ sed '10,20s/hello/world/' input.txt > output.txt
```

## cut - remove sections from each line of files
```sh
#    input field:field2:field3
#    out field
cut -d: -f1 < /path/to/files | sort
```

## diff - compare files line by line
```sh
# 比较两个文件，把结果输出到 diffline 后台执行
diff file.txt file.txt.old > diffline &
```

## sort
```bash
#!/bin/bash
#  highest filename [howmany]

filename=$1
howmany=${2:-10}
sort -nr $filename | head -$howmany
```

## compress
```bash
#!/bin/bash
filepath=$1
cd $filepath
files=$(find -iregex ".*\.\(jpg\|png\)")
echo "Working path" $filepath
echo $files
read -p 'The above files will be compressed(y/N)' choice
if [ "${choice:-y}" != "y" ]; then
    echo bye!
    exit
fi
pathto='./compressed/'
if [ ! -d $pathto ]; then
    mkdir $pathto
fi
for file in $files
do
    if [ ! -d ${pathto}${file%\/*} ]; then
        mkdir -p ${pathto}${file%\/*}
    fi
    guetzli --quality 85 --verbose $file ${pathto}${file#\.\/}
done
```
