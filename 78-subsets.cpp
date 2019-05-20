#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> subs;
    }

    void buildSubset(vector<int> &nums, int idx, vector<int> &curSub, vector<vector<int>> &allSubs)
    {
        if (idx <= 0)
        {
            allSubs.push_back(curSub);
            return;
        }
        else
        {
            buildSubset(nums, idx, curSub, allSubs);
            buildSubset(nums, idx + 1, curSub, allSubs);
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
    Solution s;
    vector<int> v = {1, 2, 3};
    vector<vector<int>> subs = s.subsets(v);
    print_matrix(subs);
    return 0;
}
