#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * 
 * Unsolved :(
 * 
 * 
 * */
class Solution
{
public:
    bool validPalindrome(string s)
    {
        bool valid = true;
        string::iterator begin = s.begin();
        string::iterator end = s.end() - 1;

        while (begin < end && valid)
        {
            if (*begin != *end)
            {
                valid = false;
                if (begin + 1 == end || *(begin + 1) == *end)
                {
                    valid = true;
                }
            }
            ++begin, --end;
        }
        return valid;
    }
};

int main()
{
    Solution s;
    string st = "deeede";
    cout << s.validPalindrome(st) << endl;
    return 0;
}