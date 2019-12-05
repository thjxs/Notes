## Issue
### Failed to connect to vagrantcloud-files-production.s3.amazonaws.com port 443: Timed out
修改 host
219.76.4.4 s3.amazonaws.com
219.76.4.4 github-cloud.s3.amazonaws.com

### backup database when vagrant box is destroyed
`backup: true`

### manually add box
```
# Rename folder to specify box version
vagrant box add BOX_NAME PATH/TO/BOX
```
