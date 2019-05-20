#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void lookAndSay(string look, int times)
    {
        for (int i = 0; i < times; i++)
        {
            look = sayWhatSee(look);
            cout << look << endl;
        }
    }
    string sayWhatSee(string look)
    {
        int ch = look[0];
        int i = 0;
        int count = 0;
        string res = "";
        while (i < look.length())
        {
            if (ch == look[i])
            {
                ++count;
                ++i;
            }
            else
            {
                res += to_string(count);
                res += ch;
                ch = look[i];
                count = 1;
                ++i;
            }
        }
        res += to_string(count);
        res += ch;
        return res;
    }
};

int main()
{
    Solution s;
    s.lookAndSay("1", 5);
    return 0;
}