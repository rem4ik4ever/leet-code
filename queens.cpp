#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> board = buildBoard(n);
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
    tryPlaceQueen(board, n, 0, 0);
    return board;
  }
  bool tryPlaceQueen(vector<vector<string>> &board, int n, int rS = 0, int cS = 0){
    printBoard(board);
    bool queenPlaced = false;
    for (int row = rS; row < board.size(); row++)
    {
      for (int col = cS; col < board.size(); col++)
      {
        if(canPlace(board, row, col)){
          board[row][col] = "Q";
          queenPlaced = true;
          printBoard(board);
          if(!tryPlaceQueen(board, n - 1, row, col)){
            board[row][col] = ".";
            queenPlaced = false;
            cout << "Backtracking" << endl;
          } else {
            --n;
          }
        } else {
          cout << "Cant be placed" << endl;
        }
      }
    }
    // printBoard(board);
    return queenPlaced;
    
  }
  bool placeQueen(int n, vector<vector<string>> &board){
    vector<vector<string>> tmpBoard = board;
    while(n > 0){
      bool queenPlaced = false;
      for (int row = 0; row < n; row++)
      {
        for (int col = 0; col < n; col++)
        {
          if(tmpBoard[row][col] == ".") {
            tmpBoard[row][col] = "Q";
            colorBoard(tmpBoard, row, col);
            printBoard(tmpBoard);
            queenPlaced = true;
          }
        }
      }
      if(queenPlaced){
        --n;
      }
    }
    board = tmpBoard;
    return true;  
  }
  void colorBoard(vector<vector<string>> &board, int row, int col) {
    for (int i = 0; i < board.size(); i++)
    {
      if(board[row][i] != "Q"){
        board[row][i] = "x";
      }
      if(board[i][col] != "Q"){
        board[i][col] = "x";
      }
    }
    int diaXrow = 0;
    int diaXcol = 0;
    if(row > col){
      diaXrow = row - col;
      diaXcol = 0;
    } else {
      diaXcol = col - row;
      diaXrow = 0;
    }
    while(max(diaXrow, diaXcol) < board.size()){
      if(board[diaXrow][diaXcol] != "Q"){
        board[diaXrow][diaXcol] = "x";
      }
      ++diaXcol;
      ++diaXrow;
    }
    bool rowGtCol = true;
    if(row > col){
      diaXrow = row + col;
      diaXcol = 0;
    } else {
      diaXcol = col + row;
      diaXrow = 0;
      rowGtCol = false;
    }
    while((rowGtCol ? diaXcol : diaXcol) < board.size()){
      if(board[diaXrow][diaXcol] != "Q"){
        board[diaXrow][diaXcol] = "x";
      }
      rowGtCol ? ++diaXcol : --diaXcol;
      rowGtCol ? --diaXrow : ++diaXrow;
    }
  } 
  bool canPlace(vector<vector<string>> &board, int row, int col) {
    for (int i = 0; i < board.size(); i++)
    {
      if(board[row][i] == "Q" || board[i][col] == "Q"){
        return false;
      }
    }
    int diaXrow = 0;
    int diaXcol = 0;
    if(row > col){
      diaXrow = row - col;
      diaXcol = 0;
    } else {
      diaXcol = col - row;
      diaXrow = 0;
    }
    while(max(diaXrow, diaXcol) < board.size()){
      if(board[diaXrow][diaXcol] == "Q"){
        return false;
      }
      ++diaXcol;
      ++diaXrow;
    }
    bool rowGtCol = true;
    if(row > col){
      diaXrow = row + col;
      diaXcol = 0;
    } else {
      diaXcol = col + row;
      diaXrow = 0;
      rowGtCol = false;
    }
    while((rowGtCol ? diaXcol : diaXcol) < board.size()){
      if(board[diaXrow][diaXcol] == "Q"){
        return false;
      }
      rowGtCol ? ++diaXcol : --diaXcol;
      rowGtCol ? --diaXrow : ++diaXrow;
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
  cout << "Resolved" << endl;
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board.size(); j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}