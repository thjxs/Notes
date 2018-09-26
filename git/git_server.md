# 服务器上的 Git

1. SSH 公钥 [link](https://help.github.com/articles/generating-ssh-keys)
ssh-keygen

2. 为服务器配置
```
#添加 git 用户
sudo adduser git
# 在用户目录添加文件夹 .ssh
mkdir .ssh && chmod 700 .ssh
touch .ssh/authorized_keys && chmod 600 .ssh/authorized_keys
# 把信任的公钥加入 authorized_keys
cat path/to/id_rsa.name.pub >> ~/.ssh/authorized_keys
etc
```
3. 新建仓库
```
mkdir /opt/git/project.git
cd /opt/git/project.git
git init --bare --shared
```

## 限制 git 登录
使用 git-shell 的受限 shell 工具
```
cat /etc/shells   # see if `git-shell` is already in there.
which git-shell   #
sudo vim /etc/shells # add path to git-shell 

sudo chsh git # and enter path to git-shell , usually: /usr/bin/git-shell
```
