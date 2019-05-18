#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // O(N^2)
    // Dynamic programming
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        // Memorize LIS count at index
        vector<int> counts = vector<int>(nums.size());
        counts[0] = 1;
        int maxVal = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            // Keep track of current max in second loop
            int maxCurr = 0;
            cout << "Should be less than: " << nums[i] << endl;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    maxCurr = max(counts[j], maxCurr);
                }
            }
            counts[i] = maxCurr + 1;
            maxVal = max(counts[i], maxVal);
        }
        return maxVal;
    }

    void print_array(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ", ";
        }
        cout << endl;
    }

    // O(N*logN)
    int lis(vector<int> &nums)
    {
        vector<int> dp(nums.size(), INT_MAX);
        for (int i = 0; i < nums.size(); i++)
        {
            *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
            print_array(dp);
        }
        return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), INT_MAX));
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lis(v) << endl;
    return 0;
}
