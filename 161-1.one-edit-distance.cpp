#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 
 * 
 * Runtime: 4 ms, faster than 98.28% of C++ online submissions for One Edit Distance.
 * Memory Usage: 9 MB, less than 8.23% of C++ online submissions for One Edit Distance.
 * 
 * Complexity O(N)
 * Space O(1)
 *
 * */
class Solution
{
public:
    bool isOneEditDistance(string s, string t)
    {
        if (s.length() > t.length())
        {
            return isOneEditDistance(t, s);
        }
        if (t.length() - s.length() > 1)
        {
            return false;
        }
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != t[i])
            {
                if (s.length() == t.length())
                {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                else
                {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
        }
        return s.length() + 1 == t.length();
    }
};

int main()
{
    Solution s;
    cout << s.isOneEditDistance("absc", "absc") << endl;
    cout << s.isOneEditDistance("ab", "acb") << endl;
    cout << s.isOneEditDistance("1213", "1203") << endl;
    cout << s.isOneEditDistance("cad", "ad") << endl;
    cout << s.isOneEditDistance("cad", "adbb") << endl;
    cout << s.isOneEditDistance("ab", "ac") << endl;
    return 0;
}