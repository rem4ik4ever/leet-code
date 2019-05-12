
//73. Set Matrix Zeroes
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        printMatrix(matrix);
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[row].size(); col++)
            {
                if (matrix[row][col] == 0)
                {
                    markZeroes(matrix, row, col);
                }
            }
        }
        zeroMarked(matrix);
        printMatrix(matrix);
    }
    void markZeroes(vector<vector<int>> &matrix, int row, int col)
    {
        for (int i = 0; i < matrix[row].size(); i++)
        {
            if (matrix[row][i] != 0)
            {
                matrix[row][i] = -111;
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][col] != 0)
            {
                matrix[i][col] = -111;
            }
        }
    }
    void zeroMarked(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == -111)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void printMatrix(vector<vector<int>> matrix)
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
        cout << endl;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    s.setZeroes(matrix);
    return 0;
}