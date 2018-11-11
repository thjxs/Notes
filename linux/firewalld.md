# Centos
## add port
firewall-cmd --zone=public --add-port=80/tcp --permanent

## remove port
firewall-cmd --zone=public --remove-port=80/tcp --permanent
