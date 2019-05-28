#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
// Memory Usage: 10.7 MB, less than 5.02% of C++ online submissions for Game of Life.
class Solution
{
public:
    int nextState(vector<vector<int>> board, int row, int col)
    {
        int near = 0;
        if (row - 1 >= 0)
        {
            if (col - 1 >= 0 && abs(board[row - 1][col - 1]) == 1)
                near++;
            if (abs(board[row - 1][col]) == 1)
                near++;
            if (col + 1 < board[row - 1].size() && abs(board[row - 1][col + 1]) == 1)
            {
                near++;
            }
        }

        // checkin sides
        if (col - 1 >= 0 && abs(board[row][col - 1]) == 1)
            near++;
        if (col + 1 < board[row].size() && abs(board[row][col + 1]) == 1)
            near++;

        // checking bottom row
        if (row + 1 < board.size())
        {
            if (col - 1 >= 0 && abs(board[row + 1][col - 1]) == 1)
                near++;
            if (board[row + 1][col] == 1)
                near++;
            if (col + 1 < board[row].size() && abs(board[row + 1][col + 1]) == 1)
                near++;
        }

        // Dead due to underpopulation
        if (board[row][col] == 1 && near < 2)
        {
            return -1;
        }
        // Remains alive due to 2 or 3 near cells
        // if (board[row][col] == 1 && (near == 2 || near == 3))
        // {
        //     return board[row][col];
        // }

        // Dies due to overpopulation
        if (board[row][col] == 1 && near > 3)
        {
            return -1;
        }
        // becomes alive
        if (board[row][col] == 0 && near == 3)
        {
            return 2;
        }

        return board[row][col];
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                board[i][j] = nextState(board, i, j);
            }
        }

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] > 0)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }
    }
};

void print_matrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (j > 0)
            {
                cout << ", ";
            }
            cout << matrix[i][j];
        }
        cout << " ]" << endl;
    }
}

int main()
{
    vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}};
    Solution s;
    print_matrix(board);
    cout << endl;
    s.gameOfLife(board);
    print_matrix(board);
    return 0;
}
