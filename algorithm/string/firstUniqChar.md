# 字符串中的第一个唯一字符

```
/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    let sa = s.split('');
    let index;
    let value;
    let tmp = [];
    for(let i = 0; i < sa.length; i++) {
        if (tmp[sa[i]] == undefined) {
            tmp[sa[i]] = 0;
        }
        tmp[sa[i]]++;
    }
    for(var key in tmp) {
        if(tmp[key] == 1) {
            value = key;
            break;
        }
    }
    for(let i = 0; i < sa.length; i++) {
        if (sa[i] == value) {
            index = i;
        }
    }
    return index != undefined ? index:(-1);
};
```

## other solution
```
var firstUniqChar = function(s) {
    for(var i = 0; i < s.length; i++) {
        if (s.lastIndexOf(s[i]) == i) {
            return 1;
        }
    }
    return -1;
}
```
