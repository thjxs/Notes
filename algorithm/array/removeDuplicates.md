# remove duplicates from sorted array

Given a sorted array nums, remove the duplicates in-place such that
each element appear only once and return the new length

```js
/**
 * removeDuplicates
 *
 * @param  {array} nums 
 * @return {number}     
 */
var removeDuplicates = function (nums) {
    if (nums.length === 0) return 0;
    let i = 0;
    for (let j = 1; j < nums.length; j += 1) {
        if (nums[i] !== nums[j]) {
            i += 1;
            if (i !== j) {
                nums[i] = nums[j];
            }
        }
    }
    return i + 1;
}
```
