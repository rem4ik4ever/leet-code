#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int i = 0;

        for (int j = i; j < nums.size(); ++j)
        {
            if (nums[i] != nums[j])
            {
                ++i;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    s.removeDuplicates(v);
    return 0;
}