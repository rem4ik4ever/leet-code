#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Solution walk through
// 1. Create memory table to Store index position of each character
// 2. Use left and right indexes to expand window
// 3. Check memo if character exists and it has position after current left index, assign new left index
// 4. Otherwise assign position to memory under character index
// Runtime: 12 ms, faster than 96.56% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 10.1 MB, less than 85.84% of C++ online submissions for Longest Substring Without Repeating Characters.

// Complexity O(N)
// Space O(1)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        return uniquesub(s, 0);
    }

    int uniquesub(string s, int index)
    {
        if (s.size() < 2)
            return s.size();
        vector<int> memo(128, -1);
        int l = -1, r = 0, len = r - l;
        for (r = 0; r < s.size(); ++r)
        {
            if (memo[s[r]] != -1 && memo[s[r]] > l)
            {
                l = memo[s[r]];
            }
            memo[s[r]] = r;
            len = max(len, r - l);
        }
        return len;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("BBBBBB") << endl;
    cout << s.lengthOfLongestSubstring("abcad") << endl;
    cout << s.lengthOfLongestSubstring("aab") << endl;
    cout << s.lengthOfLongestSubstring("dvdf") << endl;

    return 0;
}