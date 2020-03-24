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
flag *--stat* generate a diffstat

```
git diff HEAD^ --stat
# eg
 git/git_server.md | 4 +++-
 1 file changed, 3 insertions(+), 1 deletion(-)
```

# cherry-pick
Apply the changes introduced by some existing commits
```
git cherry-pick <commit>...
```
