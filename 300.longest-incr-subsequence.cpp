#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int maxIS = 0;
        int n = 0;
        lis(nums, nums.size(), &maxIS);
        return maxIS;
    }

    int lis(vector<int> &nums, int n, int *maxR)
    {
        // base case
        if (n == 1)
        {
            return 1;
        }

        int res, maxEnd = 1;

        for (int i = 0; i < n; i++)
        {
            res = lis(nums, i, maxR);
            if (nums[i - 1] < nums[n - 1] && res + 1 > maxEnd)
            {
                maxEnd = res + 1;
            }
        }

        if (*maxR < maxEnd)
        {
            *maxR = maxEnd;
        }
        return maxEnd;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(v) << endl;
    return 0;
}
