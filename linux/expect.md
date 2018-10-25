# programmed dialogue with interactive programs
```sh
#!/usr/bin/expect
set timeout 20
spawn scp -r user@host:$file ./
expect "*password:"
send "123\r"
interact
```
