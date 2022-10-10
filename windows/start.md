# Start

starts a separate window to run a specified program or command.

open file on typora

```sh
start typora /path/to/file
```

Open repository via smerge (Add `C:\Program Files\Sublime Merge` to system path)

```sh
start smerge /path/to/repository
```

## specific program

First, open `Registry Editor`, press `win + R`, then type `regedit`.
find this location: `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths`

Add new key, like `Typora.exe`, and its value(path to this program).
