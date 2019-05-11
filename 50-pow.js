/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */

// Time limit exceeded
// var myPow = function(x, n) {
//   var isNegative = false;
//   if (n < 0) {
//     isNegative = true;
//   }
//   var res = 1.0;
//   var num = Math.abs(n);
//   while (num != 0) {
//     res *= x;
//     --num;
//   }
//   if (isNegative) {
//     return (1 / res).toFixed(5);
//   }
//   return res.toFixed(5);
// };

/**
 * Recursive solution with memorization
 *  Time Complexity O(logN)
 *  Space Complexity O(n) linear
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
  var memo = {};
  if (n < 0) {
    x = 1 / x;
    n = -n;
  }
  var res = recPow(x, n, memo);
  return res;
};

function recPow(x, n, memo) {
  if (n == 0) {
    return 1;
  }
  if (memo[n]) {
    return memo[n];
  }
  var val = recPow(x * x, Math.floor(n / 2), memo) * (n % 2 > 0 ? x : 1);
  memo[n] = val;
  return memo[n];
}

console.log(myPow(2.1, 3));
