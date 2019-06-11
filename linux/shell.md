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
| Operator                | Substitution                                                 |
| ----------------------- | ------------------------------------------------------------ |
| ${#string}              | 返回字符串的长度<br /> string=word, ${#string} returns 4     |
| ${var:=word}            | 如果变量没有定义，给变量设置一个默认值<br />${count:=0}      |
| ${var:-word}            | 如果变量没有定义，返回一个默认值<br />${count:-0}            |
| ${var:+word}            | 测试一个存在的变量                                           |
| ${string:offset:length} | string=word <br />${string:2} returns *rd*. <br />${string:2:3} returns *r*. |

**path**=/home/tan/book/file.name.md

| Expression   | Result                      |
| ------------ | --------------------------- |
| ${path##/*/} | file.name.md                |
| ${path#/*/}  | tan/book/file.name.md       |
| ${path}      | /home/tan/book/file.name.md |
| ${path%.*}   | /home/tan/book/file.name    |
| ${path%%.*}  | /home/tan/book/file         |

###### replace

```bash
# 将最长匹配的 *pattern* 替换为 *string* (expecially *#* *%*)
${variable/pattern/string}   # only the first match is replaced
${variable//pattern/string}  # all matches are replaced
```

## sed 流编辑器
> [Sed 命令完全指南](https://linux.cn/article-10232-1.html)

```bash
sed -i 's/string/replacement/g' path/to/file
sed -i '/lines/s/targetstring/replacement/' path/to/file
# Example: delete the 4th line in a file
$ sed '4d' input.txt > output.txt
# Example: replace every occurrence of 'hello' with 'world' on lines 10-20
$ sed '10,20s/hello/world/' input.txt > output.txt
```

## cut - remove sections from each line of files
```bash
#    input field:field2:field3
#    out field
cut -d: -f1 < /path/to/files | sort
```

## diff - compare files line by line
```bash
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
## wc
```
# 字符长度
echo string | wc -L
```

## handle input with options
```sh
#!/usr/bin/bash
if [ -n "$(echo $1 | grep '^-[0-9][0-9]*$')" ]; then
    howmany=$1
    shift
elif [ -n "$(echo $1 | grep '^-')" ]; then
    print 'usage: highest [-N] filename'
    exit 1
else
    howmany="-10"
fi
filename=$1
sort -nr $filename | head $howmany
```

## multiple options
```sh
while [[ -n "$(echo $1 | grep '-')" ]]; do
    case $1 in
        -a ) process option -a ;;
        -b ) process option -b ;;
        -c ) process option -c ;;
        *  ) echo 'usage: alice [-a] [-b] [-c] args...'
             exit 1
    esac
    shift
done
normal processing of arguments
# This code checks $1 repeatedly as long as it starts with a dash (-). Then the
# case construct runs the appropriate code depending on which option $1 is. If 
# the option is invalid ---i.e., if it starts with a dash but isn't -a, -b
done
```
