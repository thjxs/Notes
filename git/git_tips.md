# Tips

## branch

```sh
git rev-parse --abbrev-ref HEAD
```

## delete branch

```text
git push origin -d <branch>
```

## overwrite

```text
git push origin -f
```

## commit

```sh
# amends a commit without changing its commit message
git commit --amend --no-edit
# rebase
git rebase -i master
# squash 
git merge --squash
```

## diffstat

flag *--stat* generate a diffstat

```text
git diff HEAD^ --stat
# eg
 git/git_server.md | 4 +++-
 1 file changed, 3 insertions(+), 1 deletion(-)
```

## cherry-pick

Apply the changes introduced by some existing commits

```text
git cherry-pick <commit>...
```

## revert

```text
git revert <commit>
```

## reset

```text
# branch diverged
git reset --hard <commit>
```

## find delete file

```sh
git log --diff-filter=D --summary | grep delete
```

## find file commit id

```sh
git log --all <FILEPATH>
```

## patch

```sh
git format-patch -1 [commit]

# 测试
git apply --check foo.patch

# 应用
git apply foo.patch
```

## list merged branch

> 只能检查分支是否已合并，无法区分是合并还是重置。

```shell
git branch --merged

# 未合并的
git branch --no-merged
```
