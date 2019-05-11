/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var anagramMappings = function(A, B) {
  var umap = {};
  for (var i = 0; i < B.length; i++) {
    if (!umap[B[i]]) {
      umap[B[i]] = i;
    }
  }
  var res = [];
  for (var i = 0; i < A.length; i++) {
    res.push(umap[A[i]]);
  }
  return res;
};

var res = anagramMappings([12, 28, 46, 32, 50], [50, 12, 32, 46, 28]);
console.log(res);
