# centos

* vim /etc/my.cnf
add: skip-grant-tables

* service mysqld restart

* update mysql.user set authentication_string=password('root') where user='root';

* remove my.cnf changes and restart service
