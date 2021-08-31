# 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var len = nums.length;
    var numObj = {};
    for(var i = 0; i < len; i++) {
        var current = nums[i];
        var match = target - current;
        if (match in numObj) {
            return [i, numObj[match]]
        } else {
            numObj[current] = i;
        }
    }
};
```
