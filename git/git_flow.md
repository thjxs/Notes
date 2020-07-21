## init
`git flow init`

## config
```
[gitflow "branch"]
        master = master
        develop = develop
[gitflow "prefix"]
        feature = feature/
        bugfix = bugfix/
        release = release/
        hotfix = hotfix/
        support = support/
        versiontag =
[gitflow "path"]
        hooks = .git/hooks
```

### feature
`git flow feature start <feature>`

// a few changes

// finish
`git flow feature finish <feature>`

### release
`git flow release start <version>`

//finish
`git flow release finish <version>`
