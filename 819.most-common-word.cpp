#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 
 * Complexity O(N)
 * Space O(A + B)
 * 
 * Runtime: 4 ms, faster than 99.69% of C++ online submissions for Most Common Word.
 * Memory Usage: 9.3 MB, less than 34.82% of C++ online submissions for Most Common Word.
 * 
 * 
 * 
 * */

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        string punctuation = "!?',;.";
        unordered_map<string, int> found;
        unordered_map<string, bool> banned_words;
        for (int i = 0; i < banned.size(); i++)
        {
            banned_words[banned[i]] = true;
        }

        int maxCount = 0;
        string word = "";
        string maxWord = "";
        for (int i = 0; i < paragraph.length(); i++)
        {
            if (punctuation.find(paragraph[i]) == string::npos && paragraph[i] != ' ')
            {
                word += tolower(paragraph[i]);
            }
            else
            {
                if (word.length() > 0 && !banned_words[word])
                {
                    if (found.find(word) == found.end())
                    {
                        found[word] = 1;
                    }
                    else
                    {
                        found[word] += 1;
                    }
                    if (found[word] > maxCount)
                    {
                        maxCount = found[word];
                        maxWord = word;
                    }
                    word = "";
                }
                else
                {
                    word = "";
                }
            }
        }
        if (maxWord.length() == 0 && word.length() > 0)
        {
            return word;
        }
        return maxWord;
    }
};

int main()
{
    Solution s;
    string par = "a, a, a, a, b,b,b,c, c";
    vector<string> banned = {"a"};
    string word = s.mostCommonWord(par, banned);
    cout << word << endl;
    return 0;
}