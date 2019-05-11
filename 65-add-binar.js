/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
// Slow 168ms
var addBinary = function(a, b) {
  var i = 0;
  var tmp = 0;
  var res = "";
  while (i < (a.length > b.length ? a.length : b.length)) {
    var a1 = a[a.length - 1 - i] ? parseInt(a[a.length - 1 - i]) : 0;
    var b1 = b[b.length - 1 - i] ? parseInt(b[b.length - 1 - i]) : 0;
    res = ((a1 + b1 + tmp) % 2) + res;
    console.log("a1 + b1 + tmp", a1 + b1 + tmp);
    if (a1 + b1 + tmp >= 2) {
      tmp = 1;
    } else {
      tmp = 0;
    }

    ++i;
  }
  if (tmp > 0) {
    res = tmp + res;
  }
  return res;
};

/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
// OK 64ms
var addBinary = function(a, b) {
  var tmp = 0;
  var res = "";
  var len = Math.max(a.length, b.length);
  var i = len - 1;
  a = a.padStart(len, 0);
  b = b.padStart(len, 0);
  console.log(a, b);
  while (i >= 0 || tmp) {
    var a1 = +a[i] || 0;
    var b1 = +b[i] || 0;
    var val = a1 + b1 + tmp;
    if (val === 1 || val === 0) {
      res = val + res;
      tmp = 0;
    }
    if (val === 2) {
      res = "0" + res;
      tmp = 1;
    }
    if (val === 3) {
      res = "1" + res;
      tmp = 1;
    }
    --i;
  }
  return res;
};
