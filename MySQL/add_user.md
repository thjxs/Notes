# mysql 5.7
## add user
```
CREATE USER 'username'@'host' IDENTIFIED BY 'yourpassword';
GRANT privileges ON databasename.tablename TO 'username'@'host';
flush privileges;
```
