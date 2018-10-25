after install magento2 
I try to setup this project. But I got some issue like file permisssion 
check failed.

I don't know why
But this work with me

```sh
chcon -R -t httpd_sys_rw_content_t /var/www/html/magento/
chmod -R a+w /var/www/html/magento/
```
