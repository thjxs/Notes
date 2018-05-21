to install php 7.0 on CentOS 6 or 7
```
yum -y update
yum -y install epel-release
wget https://dl.fedoraproject.org/pub/epel/epel-release-latest-6.noarch.rpm
wget https://centos6.iuscommunity.org/ius-release.rpm
rpm -Uvh ius-release*.rpm
yum -y update
```

```
yum install -y http://dl.iuscommunity.org/pub/ius/stable/CentOS/7/x86_64/ius-release-1.0-14.ius.centos7.noarch.rmp
yum -y update
```