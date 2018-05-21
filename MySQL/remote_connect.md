# 修改 mysql.user 的 host 项
* update mysql.user set host='%' where user='root';

* 增加授权