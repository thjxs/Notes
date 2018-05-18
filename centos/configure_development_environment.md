yum -y update

yum -y install httpd
rpm -Uvh http://dev.mysql.com/get/mysql57-community-release-e17-8.noarch.rpm

yum -y install mysql-community-server

# start Apache and MySql
```
systemctl start httpd
systemctl start mysqld
systemctl enable httpd
systemctl enable mysqld
```

# configure Apache for mod_rewrite