#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start)
        {
            int sum = 0;
            for (int end = start; end < nums.size(); ++end)
            {
                sum += nums[end];
                if (sum == k)
                {
                    ++count;
                }
            }
        }
        return count;
    }
};

class Solution2
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        unordered_map<int, int> map;
        map[0]++;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (map[sum - k])
            {
                count += map[sum - k];
            }
            map[sum]++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 1, 1};
    s.subarraySum(v, 2);
    return 0;
}