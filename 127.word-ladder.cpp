#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConvert(string s1, string s2)
    {
        int idx1 = 0, idx2 = 0;
        int skip = 1;
        while (idx1 < s1.length())
        {
            if (s1[idx1] != s2[idx2] && skip > 0)
            {
                --skip;
            }
            else if (s1[idx1] != s2[idx2])
            {
                return false;
            }
            ++idx1;
            ++idx2;
        }
        return true;
    }

    // Find Partition that can be transformed in 1 change
    // count steps towards making thansformation
    // if word matched with end work return steps
    // else when iteration reached, make new transformation partition
    // Previous becomes first iteration
    // First iteration becomes next transformation

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        auto iter = partition(wordList.begin(), wordList.end(), [this, &beginWord](const string val) {
            return canConvert(beginWord, val);
        });
        auto prev = wordList.begin();
        auto curr = iter;

        for (int steps = 1; prev != curr; ++steps)
        {
            for (auto first = prev; first != curr; ++first)
            {
                if (*first == endWord)
                {
                    return steps + 1;
                }
            }

            auto next = partition(curr, wordList.end(), [this, prev, curr](const string val) {
                for (auto first = prev; first != curr; ++first)
                {
                    if (canConvert(*first, val))
                    {
                        return true;
                    }
                }
                return false;
            });

            prev = curr;
            curr = next;
        }

        return 0;
    }

    void print_partition(vector<string>::iterator it, vector<string> arr)
    {
        while (it != arr.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
};

int main()
{

    Solution s;
    vector<string> v = {"a", "b", "c"};
    cout << s.ladderLength("a", "c", v) << endl;

    vector<string> v5 = {"a", "c"};
    cout << s.ladderLength("a", "c", v5) << endl;

    vector<string> v2 = {"hot", "dot", "dog", "lot", "log"};
    cout << s.ladderLength("hit", "cog", v2) << endl;

    vector<string> v3 = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << s.ladderLength("hit", "cog", v3) << endl;

    vector<string> v4 = {"hit", "dog", "dot"};
    cout << s.ladderLength("hot", "dog", v4) << endl;
    return 0;
}