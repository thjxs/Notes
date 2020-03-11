# git rebase 
```
          A---B---C topic
         /
    D---E---F---G master

    git rebase master
    git rebase master topic

                  A'--B'--C' topic
                 /
    D---E---F---G master

    git checkout master 
    git merge --ff-only topic
```

# history log
```
git log --oneline -5
git rebase -i [commit id]
```

# branch 
```
git rev-parse --abbrev-ref HEAD
```

# delete branch
```
git push origin -d <branch>
```

# overwrite
```
git push origin -f
```

# commit
```
# amends a commit without changing its commit message
git commit --amend --no-edit
# rebase
git rebase -i master
# squash 
git merge --squash
```

# diffstat
--stat
Generate a diffstat

```
git diff HEAD^ --stat
```

# cherry-pick
Apply the changes introduced by some existing commits
```
git cherry-pick <commit>...
```
