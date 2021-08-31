# git rebase

current branch is "topic"

```text
          A---B---C topic
         /
    D---E---F---G master
```

run `git rebase master` or `git rebase master topic`

the topic branch commit log will look like this

```text

                  A'--B'--C' topic
                 /
    D---E---F---G master
```

Now you can switch to master branch and merge it

```text
    git checkout master 
    git merge --ff-only topic
```

## splitting commits

turn into interactive mode
`git rebase -i <after-this-commit>`
