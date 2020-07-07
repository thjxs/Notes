## command separator [semicolon] 
```sh
echo hello; echo hi
```

## Terminator in a case option [double semicolon]
```sh
case "$variable" in
    abc) echo "\$variable = abc" ;;
    xyz) echo "\$variable = xyz" ;;
```

## partial quoting [double quote]
"*STRING*" preserves (from interpretation) most of the special characters within *STRING*

## full quoting [single quote]
'*STRING*' preserves all special characters within *STRING*. This is a stronger from of quoting than "*STRING*"

## comma operator
The comma operator links together a series of arithmetic operations. All are evaluated, but only the last one is returned
```sh
# concatenate string
# echo /{,usr/}bin
# /bin /usr/bin
for file in /{,usr/}bin/c*
do
    if [ -x "$file" ]; then
        echo $file
    fi
done
```

## variable substitution (contents of a variable)
```sh
name=xiaoming
echo $name # xiaoming
```

## parameter substitution
May be used for concatenating variables with strings
```sh
PATH=${PATH}:/opt/bin
```

${parameter-default}, ${parameter:-default}
if parameter not set, use default
```sh
var1=1
var2=2
echo ${var1-$var2}
echo ${var3-$var2}

variable=
echo "${variable-0}"  # (no output)
echo "${variable:-1}" # 1
```

${parameter=default}, ${parameter:=default}
if parameter not set, set it to default
```sh
echo ${var=abc} # abc
echo ${var=xyz} # abc
```

*more about abs-guide p131*

## quoted string expansion
```sh
quote=$'\042'
echo $quote # "
```

## positional parameters $* $@
```sh
index=1
for arg in "$@"
do
    echo "Arg #$index $arg" 
    let "index+=1"
done

index=1
for arg in "$*"
do
    echo "Arg #$index $arg"
    let "index+=1"
done
# invoked ./scriptname.sh 1 2 3 
# Arg #1 1 2 3  
# Arg #1 1
# Arg #2 2
# Arg #3 3
```
