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
```sh
git log --oneline -5
git rebase -i [commit id]
```

# git push origin -d <branch>

# git push origin -f

# Create a global .gitignore
` git config --global core.excludesfile ~/.gitignore_global`



## commit 

* --amend: amend previous commit
* 