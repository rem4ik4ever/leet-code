#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> board;

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> board = buildBoard(n);
    backtrack(0);
    return board;
  }
private: 
  vector<vector<string>> buildBoard(int n) {
    vector<vector<string>> board;
    for(int i = 0; i < n; ++i){
      vector<string> row;
      row.resize(n, "."); 
      board.push_back(row);
    }
    return board;
  }


  void backtrack(int row) {
    for (int col = 0; col < board.size(); col++)
    {
      if(canPlace(board, row, col)){
        board[row][col] = "Q";
        if(row + 1 != board.size()){
          backtrack(row + 1);
        }
      }
    }
    
    
  }

  bool canPlace(vector<vector<string>> board, int row, int col) {
    cout << "in can place" << endl;
    for (int r = row - 1; r >= 0; r--)
    {
      if(board[r][col] == "Q"){
        return false;
      }
    }
    for (int c = col - 1; c >= 0; c--)
    {
      if(board[row][c] == "Q"){
        return false;
      }
    }
    while(row - 1 >= 0 || col - 1 >= 0){
      if(board[row-1][col-1] == "Q"){
        return false;
      }
    }
    return true;
  } 
  void printBoard(vector<vector<string>> board){
    for (int i = 0; i < board.size(); i++)
      {
        for (int j = 0; j < board.size(); j++)
        {
          cout << board[i][j] << " ";
        }
        cout << endl;
      }
      cout << "Queen placed END" << endl;
  }
};


int main(){

  Solution s = Solution();
  vector<vector<string>> board = s.solveNQueens(4);
  return 0;
}