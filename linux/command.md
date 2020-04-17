# find
1. 批量删除文件
` find ./ -name "*.log" -exec rm -rf {} \; `
2. 修改子目录的文件权限
`find -type f -exec chmod 644 {} \;`

# 批量修改文件名
```bash
#!/bin/bash
for files in $(find ./ -iname "*.jpg")
do
    # 移除文件名的括号
    filename=${files//[()]/}
    mv $files $filename
done
```
# 读取文件的指定行数并输出到另一个文件
```bash
#!/bin/bash
file="/etc/passwd"
# 将fd3的内容写入/tmp/mypasswd中
exec 3>/tmp/mypasswd
for i in 2 4 6 8 10 13 15;do
line=`head -$i $file | tail -1`
echo "$line"
# 将内容写入 fd3
echo "$line" >&3
done
# 关闭标指输出
exec 3>&-
```
# 创建目录 文件 列出文件或目录
```bash
#!/bin/bash
date
mkdir -pv /tmp/lstest
cd /tmp/lstest
mkdir a1d b56e 6test
touch xy x2y 732
# 列出以 a | x | 6 开头的文件
ls [ax6]*
# 列出 字母跟数字开头的文件
ls [[:alpha:]][[:digit:]]*
```
# cp
```sh
# 同一个目录复制多个文件
cp path/{f1,dir1,f2,dir2} path/target

# 共同前缀
cp /path/pre{1..3} path/target
```

# mv
```sh
# rename "foo-bar" to "foo-baz"
mv foo{-bar, -baz}
```

# info
```sh
df -h
free
cat /proc/cpuinfo
ps -ef | grep process  # pid 
netstat -tunlp | grep 22
```
