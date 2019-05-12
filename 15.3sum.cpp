#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        }
};

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
    Solution s;
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    s.threeSum(input);
    return 0;
}