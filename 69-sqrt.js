/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
  return binarySqrt(1, x, x);
};

function binarySqrt(left, right, square) {
  var mid = Math.floor((left + right) / 2);
  sqr = mid * mid;
  if (sqr == square || left === mid) {
    return mid;
  } else if (sqr > square) {
    return binarySqrt(left, mid, square);
  } else if (sqr <= square) {
    return binarySqrt(mid, right, square);
  }
  return 0;
}

console.log(mySqrt(1));
