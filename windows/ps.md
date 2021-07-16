# awesome shell

## compress archive

```ps
$compress = @{
  Path = "C:\Users\tan\file", "C:\Users\tan\folder"
  CompressionLevel = "Fastest"
  DestinationPath = "C:\Users\tan\ca.zip"
}
Compress-Archive @compress
```

## get file hash
```ps
Get-FileHash .\file
```
