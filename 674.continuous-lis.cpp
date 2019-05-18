#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int maxS = 1;
        vector<int>::iterator st = nums.begin();
        vector<int>::iterator et = nums.end() - 1;
        int currMax = 1;
        while (et >= (nums.begin() + nums.size() / 2))
        {
            while (st <= et)
            {
                if (*st >= *et)
                {
                    maxS = max(currMax, maxS);
                    currMax = 1;
                }
                else
                {
                    if (*st < *(st + 1))
                    {
                        cout << *st << " ";
                        ++currMax;
                    }
                    else
                    {
                        maxS = max(currMax, maxS);
                        currMax = 1;
                    }
                }
                ++st;
            }
            --et;
            st = nums.begin();
        }
        return maxS;
    }
    int findLengthOfLCIS2(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int maxInc = 0;
        int inc = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < nums[i + 1])
            {
                ++inc;
            }
            else
            {
                maxInc = max(maxInc, inc);
                inc = 1;
            }
        }
        return max(maxInc, inc);
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 2, 2, 2, 2};
    cout << s.findLengthOfLCIS(v) << endl;
    return 0;
}