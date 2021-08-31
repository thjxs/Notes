# Running as a daemon

`./bin/elasticsearch -d -p pid`

## Install

```bash
# install signing key
rpm --import https://artifacts.elastic.co/GPG-KEY-elasticsearch
# create repository
elasticsearch="[elasticsearch-5.x]
name=Elasticsearch repository for 5.x packages
baseurl=https://artifacts.elastic.co/packages/5.x/yum
gpgcheck=1
gpgkey=https://artifacts.elastic.co/GPG-KEY-elasticsearch
enabled=1
autorefresh=1
type=rpm-md
"
echo "$elasticsearch" > "/etc/yum.repos.d/elasticsearch.repo"
# install
yum install elasticsearch
```

## java env

```bash
export JAVA_HOME=/usr/lib/jvm/jdk1.8.0_191
export PATH=${JAVA_HOME}/bin:$PATH
```
