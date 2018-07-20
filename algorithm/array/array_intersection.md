## 计算两个数组的交集

```
var intersec = function(nums1, nums2) {
    const map = {};
    const res = [];
    nums1.forEach(function(v) {
        map[v]?map[v]++:map[v]=1;
    });
    nums2.forEach(function(v) {
        if (map[v]) {
            res.push(v);
            map[v]--;
        }
    })
    return res;
}
```
