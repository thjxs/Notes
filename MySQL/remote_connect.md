# 查看 mysql user

`select user,host from mysql.user;`

## 修改 mysql.user 的 host 项

`grant all privileges on *.* to 'user'@'xxx.xxx.xxx.xxx' identified by 'password';`

## 刷新权限

`flush privileges;`
