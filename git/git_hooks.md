# serve
* post-receive
```sh
#!/bin/sh
# checkout files to a specific worktree when receive a push
while read oldrev newrev ref
do
    if [[ $ref =~ .*/master$ ]]; then
        git --work-tree=/path/to/work-tree --git-dir=/path/to/repo checkout -f
    fi

    if [[ $ref =~ .*/feature-branch$ ]]; then
        git --work-tree=/path/to/work-tree --git-dir=/path/to/repo checkout -f
    fi
done
```
