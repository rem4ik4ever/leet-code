#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Runtime: 8 ms, faster than 99.33% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage: 10.1 MB, less than 44.10% of C++ online submissions for Longest Consecutive Sequence.
// Complexity O(N) numbers in nums array
// Space O(N) memo for each number in array

class Solution
{
public:
    void print_array(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    int longestConsecutive(vector<int> &nums)
    {
        int longest = 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> memo;
        for (int i = 0; i < nums.size(); ++i)
        {

            memo[nums[i]] = memo[nums[i] - 1] + 1;
            cout << memo[nums[i]] << endl;
            longest = max(longest, memo[nums[i]]);
        }

        return longest;
    }
};

int main()
{
    Solution s;
    vector<int> v = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(v) << endl;
    return 0;
}
