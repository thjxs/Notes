## keep PHP7 fast

1. Opcache
```
zend_extension=opcache.so
opcache.enable=1
opcache.enable_cli=1
```
2. HugePage
```
# centos
sysctl vm.nr_hugepages=512
# ubuntu put vm.nr_hugepages in /etc/sysctl.conf
cat /proc/meminfo | grep Huge
# php.ini
opcache.huge_code_page=1
```
