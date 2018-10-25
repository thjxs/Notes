```

    ^__^
    (OO)\_______
    (__)\       )\/\
        ||-----w |
        ||      ||


```
# Add rules
```sh
auditctl -l
auditctl -w /pathto/file -p rwxa
auditctl -w /path/directory
```
# Log
```sh
ausearch -f file
aureport
```
