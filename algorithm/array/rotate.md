
var rotate = function(matrix) {
    let len = matrix.length - 1;
    for(let i = 0; i < matrix.length; i++) {
        for(let j = i; j < len - i; j++) {
            let tmp = matrix[i][j];
            matrix[i][j] = matrix[len-j][i];
            matrix[len-j][i] = matrix[len-i][len-j];
            matrix[len-i][len-j] = matrix[j][len-i];
            matrix[j][len-i] = tmp;
        }
    }
};

```
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    matrix.reverse();
    for(let i = 0; i < matrix.length; i++){
      for(let j = 0; j < i; j++){
        # ES6 数组交换
        [matrix[i][j], matrix[j][i]] =[matrix[j][i],matrix[i][j]]
      }
    }
};
```
