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

# Create a global .gitignore
` git config --global core.excludesfile ~/.gitignore_global`

# commit
```
# amend previous commit
git commit -amend
```
