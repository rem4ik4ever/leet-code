#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Pattern.
// Memory Usage: 8.7 MB, less than 41.89% of C++ online submissions for Word Pattern.

//Complexity O(2 * N) = O(N)
//Space O(N)
class Solution
{
public:
    void print_array(vector<string> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    bool wordPattern(string pattern, string str)
    {
        vector<string> words;
        // Splitting string into words
        int st = 0;
        int et = 0;
        while (et != str.length())
        {
            if (str[et] == ' ')
            {
                words.push_back(str.substr(st, et - st));
                ++et;
                st = et;
            }
            ++et;
        }
        words.push_back(str.substr(st, str.length()));

        // If number of words is same as pattern length
        if (words.size() != pattern.length())
        {
            return 0;
        }
        unordered_map<string, char> map;
        unordered_map<char, bool> taken;

        auto iter = words.begin();
        for (char ch : pattern)
        {
            if (!map[*iter] && !taken[ch])
            {
                map[*iter] = ch;
                taken[ch] = true;
            }
            else if (map[*iter] != ch)
            {
                return false;
            }
            ++iter;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat fist") << endl;
    return 0;
}