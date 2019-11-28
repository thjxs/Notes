## $remote_addr
client address
```
location /ip {
    default_type text/plain;
    return 200 $remote_addr;
}
```
## location regex
* = 
* ~
* ~\*
* !~
* !~*
* ^
* $
* \
* *
* 
