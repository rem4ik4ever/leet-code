#include <iostream>
#include <vector>

using namespace std;


/**
 * Slow
 * Runtime: 896 ms, faster than 5.77% of C++ online submissions for Search a 2D Matrix II.
 * Memory Usage: 13 MB, less than 9.81% of C++ online submissions for Search a 2D Matrix II.
 * 
 * This solution is somewhat close to Binary Search + brute force. 
 * However initial thought was very close to Intuition search 
 * 
 * */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if(!matrix.size() || !matrix[0].size()){
        return false;
      }
      bool found = false;

      int rowIdx = 0, colIdx = 0;
      // Find edge value indexes
      while(colIdx + 1 < matrix[rowIdx].size() && matrix[rowIdx][colIdx + 1] <= target){
        if(matrix[rowIdx][colIdx] == target) {
          found = true;
          break;
        }
        colIdx++;
      }
      while(rowIdx + 1 < matrix.size() && matrix[rowIdx + 1][0] <= target && !found){
        if(matrix[rowIdx][0] == target) {
          found = true;
          break;
        }
        rowIdx++;
      }
      for (int col = colIdx; col >= 0 && !found; col--)
      {
        for (int  row = rowIdx; row >= 0 && !found; row--)
        {
          if(matrix[row][col] == target){
            found = true;
            break;
          }
        } 
      }
      return found;
    }
};

/**
 * 
 * 
 * Intuitive Solution 
 * Giving the fact that Matrix is sorted we can navigate from left bottom to right up to find target element
 * 
 * Runtime: 64 ms, faster than 97.12% of C++ online submissions for Search a 2D Matrix II.
 * Memory Usage: 13 MB, less than 6.79% of C++ online submissions for Search a 2D Matrix II.
 * 
 * */


class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()){
          return false;
        }
        bool found = false;
        int colIdx = 0, rowIdx = matrix.size() - 1;

        while(!found) {
          if(matrix[rowIdx][colIdx] ==  target) {
            found = true;
            break;
          } else if(matrix[rowIdx][colIdx] > target) {
            rowIdx--;
            if(rowIdx < 0){
              break;
            }
          } else {
            colIdx++;
            if(colIdx == matrix[0].size()){
              break;
            }
          }
        }
        return found;
    }
};


class Solution3 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()){
          return false;
        }
        bool found = false;
        int colIdx = 0, rowIdx = matrix.size() - 1;

        while(!found) {
          if(matrix[rowIdx][colIdx] ==  target) return found = true;
          
          matrix[rowIdx][colIdx] > target ? rowIdx-- : colIdx++;
          if(rowIdx < 0 || colIdx == matrix[0].size()) break;
        }
        return found;
    }
};



/**
 * Discussion:
 * Brute force solution wher looping through every row is very slow.
 * Complexity becomes O(M**N)
 * Where M is number or rows and N is number of Columns
 * 
 * Proposing solution is to find row and column edge index where value will be less or equals target value
 * Considering the fact that matrix is already sorted
 * That way we will have less iterations 
 * 
 * eg. in case of Given Matrix 
 * matrix = {
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
  };

  and Target = 5

  Row Edge value will be 4 and Column Edge value will be 3
 * 
 * */
int main() {
  Solution2 s;
  vector<vector<int>> matrix = {
    {-1},
    {-1}
  };
  s.searchMatrix(matrix, 0);
  return 0;
}