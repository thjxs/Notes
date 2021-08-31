# Install

## yum

1. using Yum Repository

    ```sh
    wget https://dev.mysql.com/get/mysql80-community-release-el7-1.noarch.rpm
    rpm -Uvh mysql80-community-release-el7-1.noarch.rpm
    ```

2. Selecting a Release Series

    ```sh
    yum repolist all | grep mysql
    yum-config-manager --disable mysql80-community
    yum-config-manager --enable mysql57-community
    yum repolist enabled | grep mysql   ## check
    ```

3. Installing mysql

    ```sh
    yum install -y mysql-community-server
    ```

4. Starting the mysql server

    ```sh
    service mysqld start
    service mysqld status
    # update superuser account root@localhost
    grep 'temporary password' /var/log/mysqld.log
    mysql -uroot -p
    ALTER USER 'root'@'localhost' IDENTIFIED BY 'MyNewPass4!';
    ```
