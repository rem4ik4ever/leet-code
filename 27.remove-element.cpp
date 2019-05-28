#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
// Memory Usage: 8.7 MB, less than 58.16% of C++ online submissions for Remove Element.
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
        {
            if (nums[0] != val)
            {
                return 1;
            }
            return 0;
        }
        int j = 0;
        for (int i = j; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                nums[j] = nums[i];
                ++j;
            }
        }
        return j;
    }
};