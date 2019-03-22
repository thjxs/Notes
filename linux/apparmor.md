> Refer [https://help.ubuntu.com/community/AppArmor](https://help.ubuntu.com/community/AppArmor)

# install apparmor-profiles
# Usage
```sh
aa-genprof /path/to/bin
aa-status
aa-complain /path/to/bin
aa-enforce /path/to/bin
```

# disable
```sh
systemctl stop apparmor
systemctl disable apparmor
# 16.04
invoke-rc.d apparmor stop
update-rc.d -f apparmor remove
```
# enable
1. ensure apparmor is not disalbed in /etc/default/grup
2. ensureing that the apparmor package is installed
3. enabling the systemd unit: systemctl enable apparmor systemctl start apparmor

## 16.04 
```sh
invoke-rc.d apparmor start 
update-rc.d apparmor start 37 S .
```

# Reload profile
```sh
service apparmor reload
apparmor_parser -r /etc/apparmor.d/profile.name
```
