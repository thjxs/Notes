# Change password

## centos

* vim /etc/my.cnf
add: skip-grant-tables

* service mysqld restart

* update mysql.user set authentication_string=password('root') where user='root';

* remove my.cnf changes and restart service

## Ubuntu

* cat /etc/mysql/debian.cnf

* try 'debian-sys-maint' this user

* then update authentication_string

* sudo mysql -u root -p

> [password validation](https://dev.mysql.com/doc/refman/8.0/en/validate-password-options-variables.html)
