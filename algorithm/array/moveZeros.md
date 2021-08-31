# 给定一个数组，将所有 0 移动到数组末尾，保持非零元素的相对顺序

```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let pos = 0;
    for(let i = 0; i < nums.length ; i++) {
        if(nums[i] !== 0) {
            nums[pos] = nums[i]
            pos++
        }
    }
    for(; pos < nums.length; pos++) {
        nums[pos] = 0
    }

};
```
