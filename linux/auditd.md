```

    ^__^
    (OO)\_______
    (__)\       )\/\
        ||-----w |
        ||      ||


```
# 编辑规则
auditctl -l
auditctl -w /pathto/file -p rwxa
auditctl -w /path/directory

# 查看记录
ausearch -f /pathto/file

# 查看报告
aureport
