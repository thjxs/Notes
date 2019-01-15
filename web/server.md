# lemp

## Nginx

> [nginx](http://nginx.org/en/linux_packages.html#stable)

```
rpm --import http://nginx.org/keys/nginx_signing.key
rpm -ivh http://nginx.org/packages/centos/7/noarch/RPMS/nginx-release-centos-7-0.el7.ngx.noarch.rpm
yum install nginx 
```


## PHP

* centos yum
```
rpm -Uvh https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
rpm -Uvh https://mirror.webtatic.com/yum/el7/webtatic-release.rpm
```

## MySQL

> [mysql](https://dev.mysql.com/doc/mysql-yum-repo-quick-guide/en/)

* yum repository
```
rpm -Uvh https://dev.mysql.com/get/mysql80-community-release-el7-1.noarch.rpm
yum repolist all | grep mysql
yum-config-manager --disable mysql80-community
yum-config-manager --enable mysql57-community
# verify subrepositories
yum repolist enabled | grep mysql
# install 
yum install mysql-community-server
# start service 
systemctl start mysqld
# alter user root's password
grep 'temporary password' /var/log/mysqld.log
```
