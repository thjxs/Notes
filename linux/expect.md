# programmed dialogue with interactive programs
```
#!/usr/bin/expect
set timeout 20
spawn scp -r user@host:$file ./
expect "*password:"
send "123\r"
interact
```
