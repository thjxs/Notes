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
```
