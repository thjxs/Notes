# Git config

```
[init]
    defaultBranch = main

[user]
    name = thjxs
    email = tanhongjian@outlook.com

[includeIf "gitdir:~/work/"]
    path = ~/work/.gitconfig

[credential]
    helper = store
[core]
	excludesfile = ~/.gitignore
```

```text
# ~/work/.gitconfig
[core]
sshCommand = ssh -i /path/to/workUser/key/file
[user]
    name = workUser
    email = workEmail
```
