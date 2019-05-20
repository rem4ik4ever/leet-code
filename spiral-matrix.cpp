#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void fillSide(vector<vector<int>> &matrix, int i, int j, char lastAction, int val)
{
    if (matrix[i][j] != 0)
    {
        return;
    }
    // up
    if (lastAction == 'u')
    {
        while (j < matrix.size() && matrix[i][j] == 0)
        {
            matrix[i][j] = val;
            ++j;
            ++val;
        }
        --j;
        ++i;
        fillSide(matrix, i, j, 'r', val);
    }
    if (lastAction == 'r')
    {
        while (i < matrix.size() && matrix[i][j] == 0)
        {
            matrix[i][j] = val;
            ++val;
            ++i;
        }
        --j;
        --i;
        fillSide(matrix, i, j, 'd', val);
    }
    if (lastAction == 'd')
    {
        while (j >= 0 && matrix[i][j] == 0)
        {
            matrix[i][j] = val;
            ++val;
            --j;
        }
        ++j;
        --i;
        fillSide(matrix, i, j, 'l', val);
    }
    if (lastAction == 'l')
    {
        while (i >= 0 && matrix[i][j] == 0)
        {
            matrix[i][j] = val;
            ++val;
            --i;
        }
        ++i;
        ++j;
        fillSide(matrix, i, j, 'u', val);
    }
}
vector<vector<int>> buildMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int i = 0;
    int j = 0;
    fillSide(matrix, i, j, 'u', 1);
    return matrix;
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
}

int main()
{

    int n = 8;
    printMatrix(buildMatrix(n));

    return 0;
}