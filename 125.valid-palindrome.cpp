#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Runtime: 8 ms, faster than 96.35% of C++ online submissions for Valid Palindrome.
// Memory Usage: 9.6 MB, less than 12.05% of C++ online submissions for Valid Palindrome.

//Complexity O(N)
//Space O(1)
class Solution
{
public:
    bool isValid(char c)
    {
        return (isalpha(c) || isdigit(c));
    }

    bool isPalindrome(string s)
    {
        int st = 0;
        int et = s.length() - 1;
        while (st < et)
        {
            if (!isValid(s[st]))
            {
                ++st;
            }
            else if (!isValid(s[et]))
            {
                --et;
            }
            else
            {
                if (tolower(s[st]) != tolower(s[et]))
                {
                    return false;
                }
                ++st;
                --et;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome("1233421") << endl;
    return 0;
}