# Start
starts a separate window to run a specified program or command.

open file on typora
```
start typora /path/to/file
```

## specific program
First, open `Registry Editor`, press `win + R`, then type `regedit`.
find this location: `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths`

Add new key, like `Typora.exe`, and its value(path to this program).
