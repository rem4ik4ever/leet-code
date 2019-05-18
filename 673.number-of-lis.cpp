#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        vector<int> counts(nums.size(), 1);
        vector<int> lenghts(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    if (lenghts[j] >= lenghts[i])
                    {
                        lenghts[i] = lenghts[j] + 1;
                        counts[i] = counts[j];
                    }
                    else if (lenghts[j] + 1 == lenghts[i])
                    {
                        counts[i] += counts[j];
                    }
                }
            }
        }
        int longest = 0, ans = 0;

        for (int i = 0; i < lenghts.size(); i++)
        {
            longest = max(longest, lenghts[i]);
        }

        for (int i = 0; i < counts.size(); i++)
        {
            if (lenghts[i] == longest)
            {
                ans += counts[i];
            }
        }

        return ans;
    }

    void print_array(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 3, 5, 4, 7};
    cout << s.findNumberOfLIS(v) << endl;
    return 0;
}