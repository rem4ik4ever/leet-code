#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
    vector<int> makeNums(string s)
    {
        vector<int> res;
        auto num = s.begin();
        for (int i = 0; i < s.length(); ++i)
        {
            res.push_back(s[i] - '0');
        }
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = s.length() - 1; j > i; --j)
            {
                string num = s.substr(i, j - i);
                res.push_back(stoi(num));
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }

    void print(vector<int> nums)
    {
        for (int num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<string> addOperators(string num, int target)
    {
        bool palindrome = isPalindrome(num);
        vector<string> result;
        if (num.length() == 0)
        {
            return result;
        }
        vector<int> nums = makeNums(num);
        // print(nums);

        string current = "";
        current += num[0];

        makeTarget(nums, nums[0], 1, current, target, result, palindrome);
        return result;
    }

    void makeTarget(vector<int> nums, int currentSum, int idx, string exp, int target, vector<string> &res, bool palindrome)
    {
        if (idx == nums.size())
        {
            return;
        }
        // cout << exp << " " << currentSum << endl;
        if (currentSum == target)
        {
            res.push_back(exp);

            if (palindrome)
            {
                string tmp = exp;
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
            }
            return;
        }

        if ((long long)currentSum * (long long)nums[idx] <= INT_MAX && (long long)currentSum * (long long)nums[idx] >= INT_MIN)
        {
            makeTarget(nums, currentSum * nums[idx], idx + 1, exp + '*' + to_string(nums[idx]), target, res, palindrome);
        }

        if ((long long)currentSum + (long long)nums[idx] <= INT_MAX && (long long)currentSum + (long long)nums[idx] >= INT_MIN)
        {
            makeTarget(nums, currentSum + nums[idx], idx + 1, exp + '+' + to_string(nums[idx]), target, res, palindrome);
        }

        if ((long long)currentSum - (long long)nums[idx] <= INT_MAX && (long long)currentSum - (long long)nums[idx] >= INT_MIN)
        {
            makeTarget(nums, currentSum - nums[idx], idx + 1, exp + '-' + to_string(nums[idx]), target, res, palindrome);
        }
        // sum
    }
};