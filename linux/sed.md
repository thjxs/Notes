# sed 流编辑器

> [Sed 命令完全指南](https://linux.cn/article-10232-1.html)

```bash
sed -i 's/string/replacement/g' path/to/file
sed -i '/lines/s/targetstring/replacement/' path/to/file
# Example: delete the 4th line in a file
sed '4d' input.txt > output.txt
# Example: replace every occurrence of 'hello' with 'world' on lines 10-20
sed '10,20s/hello/world/' input.txt > output.txt
# Delete empty or blank lines
sed '/^$/d' input.txt
# Delete multiple lines 
sed '1d;5d;9d;$d' input.txt
# Replace regular express "test" > "newValue"
sed 's/"test"/"newValue"' path/to/file
```

## Replace

```bash
# example file
# 1 Unix unix unix 23
# 2 linux Linux 34
# 3 linuxunix UnixLinux
# linux /bin/bash CentOS Linux OS
# Linux is free and opensource operating system

# Find and Replace the 'first' event of the pattern on a line 
sed 's/unix/linux/' input
# Find and Replace the 'Nth' Occurrence of the pattern on a line 
# use /1, /2, /n, etc...
sed 's/unix/linux/2' input
# Replace all instances of the pattern in a line 
sed 's/unix/linux/g' input
# Replace the pattern for all instances in a line from the 'Nth' event
sed 's/unix/linux/3g' input
# Replace the pattern on a specific line number
sed '2 s/unix/linux/g' input
# Replace pattern in a range of lines
sed '1,3 s/unix/linux/g' input
# Find and change the pattern in the last line
sed '$ s/unix/linux/g' input
# Replace the pattern with only right word in a line
sed 's/\blinux\b/unix/g' input
# Search and Replace the pattern with case insensitive 
sed 's/Unix/Linux/gI' input
# Replace a string that contains the delimiter character
sed 's/\/bin\/bash/\/usr\/bin\/fish/g' input
sed 's|/bin/bash|/usr/bin/fish|g' input
# Replace digits with a given pattern
sed 's/[0-9]/number/g' input
# Replace only two digit numbers with pattern
sed 's/\b\([0-9]\{2\}\)\b/numbers/g' input
# Print only Replaced lines with the sed command
sed -n 's/unix/linux/p' input
# Run multiple sed commands at once
sed -e 's/linuxunix/LINUXUNIX/g' -e 's/CentOS/RHEL8/g' input
# Replace the entire line if the given pattern matches
sed '/OS/ c\
New line
' input
# Search and replace lines that matches a pattern
sed '/OS/ s/Linux/ArchLinux/' input
```
