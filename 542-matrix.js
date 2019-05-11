// NOT SOLVED

var visitedIndexes = {};
var updateMatrix = function(matrix) {
  for (var col = 0; col < matrix.length; ++col) {
    for (var row = 0; row < matrix.length; ++row) {
      if (matrix[row][col] === 1) {
        matrix[row][col] = findZero(row, col, matrix, 1);
      }
    }
  }
  return matrix;
};

function findZero(row, col, matrix) {
  if (row + 1 < matrix.length) {
    matrix[row + 1][col];
  }
}

var input = [[0, 0, 0], [0, 1, 0], [1, 1, 1]];

var res = updateMatrix(input);
console.log(res);
