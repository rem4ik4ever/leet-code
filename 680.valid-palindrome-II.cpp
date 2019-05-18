#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 
 * Complexity O(N)
 * Space O(1)
 * 
 * Solution: 
 *  Due to the fact that we can only skip 1 char 
 *  We will check if substring from both cases
 *  startPointer + 1 and endPointer - 1
 *  If any of them return true means it is a valid palindrome
 * 
 * */
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int skip = 1;
        int st = 0;
        int et = s.length() - 1;
        return isPalindrome(s, st, et, 1);
    }

    bool isPalindrome(string s, int st, int et, int skip)
    {
        int valid = true;
        while (st < et && valid)
        {
            if (s[st] == s[et])
            {
                ++st;
                --et;
            }
            else if (skip > 0)
            {

                if (s[st + 1] == s[et])
                {
                    if (isPalindrome(s, st + 1, et, 0))
                    {
                        return true;
                    }
                }
                if (s[st] == s[et - 1])
                {
                    if (isPalindrome(s, st, et - 1, 0))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                valid = false;
            }
        }
        return valid;
    }
};

int main()
{
    Solution s;
    cout << s.validPalindrome("eeccccbebaeeabebccceea") << endl;
    return 0;
}