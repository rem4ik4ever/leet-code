#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// Not solved.
class Solution
{
public:
    int myAtoi(string str)
    {
        unsigned int num = 0;
        bool negative = false;
        bool valid = true;
        string nums = "0123456789";
        string::iterator it = str.begin();
        bool overflow = false;
        while (valid && it != str.end())
        {
            if (!negative && *it == '-')
            {
                if ((it - 1) >= str.begin() && *(it - 1) == '+')
                {
                    valid = false;
                    num = 0;
                    break;
                }
                negative = true;
                ++it;
            }
            else if (valid && (*it == ' ' || (*it == '0' && num == 0)))
            {
                if (*it == '0' && (it + 1) != str.end() && *(it + 1) == ' ')
                {
                    valid = false;
                    num = 0;
                    break;
                }
                ++it;
            }
            else if (*it == '+')
            {
                if ((it - 1) >= str.begin() && *(it - 1) == '-')
                {
                    valid = false;
                    num = 0;
                    break;
                }
                ++it;
            }
            else if (valid && nums.find(*it) == string::npos)
            {
                valid = false;
                break;
            }
            else
            {
                int prev = num;
                num = num * 10 + ((int)*it - '0');
                // cout << prev << " " << num << endl;
                if (prev > num / 10 || num - 1 >= INT_MAX)
                {
                    overflow = true;
                    break;
                }
                ++it;
            }
        }
        if (overflow && negative)
        {
            return INT_MIN;
        }
        else if (overflow && !negative)
        {
            return INT_MAX;
        }
        else
        {
            if (negative)
            {
                return num * -1;
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    cout << (s.myAtoi("    -42") == -42 ? "true" : "false") << endl;
    cout << (s.myAtoi("4193 with words") == 4193 ? "true" : "false") << endl;
    cout << (s.myAtoi("words and 987") == 0 ? "true" : "false") << endl;
    cout << (s.myAtoi("-91283472332") == -2147483648 ? "true" : "false") << endl;
    cout << (s.myAtoi("91283472332") == 2147483647 ? "true" : "false") << endl;
    cout << (s.myAtoi("+-2") == 0 ? "true" : "false") << endl;
    cout << (s.myAtoi("-000000000000001") == -1 ? "true" : "false") << endl;
    cout << (s.myAtoi("   +0 123") == 0 ? "true" : "false") << endl;
    cout << (s.myAtoi("010") == 10 ? "true" : "false") << endl;
    cout << (s.myAtoi("2147483648") == INT_MAX ? "true" : "false") << endl;
    cout << (s.myAtoi("-6147483648") == INT_MIN ? "true" : "false") << endl;

    return 0;
}
