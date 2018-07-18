# find
1. 批量删除文件
` find ./ -name "*.log" -exec rm -rf {} \; `

# 批量修改文件名
```
#!/bin/bash
for files in $(find ./ -iname "*.jpg")
do
    filename=${files//[()]/}
    mv $files $filename
done
```
