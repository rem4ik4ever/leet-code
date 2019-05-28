#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stk;
        stk.push(-1);
        int maxVal = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if (stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    maxVal = max(maxVal, i - stk.top());
                }
            }
        }
        return maxVal;
    }
};

int main()
{
    Solution s;
    cout << s.longestValidParentheses(")()())") << endl;
    cout << s.longestValidParentheses("(()()()") << endl;
    cout << s.longestValidParentheses("(()") << endl;
    cout << s.longestValidParentheses("") << endl;
    cout << s.longestValidParentheses("(((((((") << endl;
    cout << s.longestValidParentheses(")))))") << endl;
    cout << s.longestValidParentheses(")))))(") << endl;
    cout << s.longestValidParentheses("()(()") << endl;
    cout << s.longestValidParentheses(")()())()()(") << endl;
    cout << s.longestValidParentheses("(()(((()") << endl;

    return 0;
}