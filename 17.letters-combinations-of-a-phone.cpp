#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * Backtrack solution 
 * Complexity O(3^N x 4^M)
 * 
 * Runtime: 4 ms, faster than 98.69% of C++ online submissions for Letter Combinations of a Phone Number.
 * Memory Usage: 8.7 MB, less than 53.83% of C++ online submissions for Letter Combinations of a Phone Number.
 * 
 * 
 * 
 * */
class Solution
{
public:
  string getNumberString(char num)
  {
    switch (num)
    {
    case '2':
      return "abc";
    case '3':
      return "def";
    case '4':
      return "ghi";
    case '5':
      return "jkl";
    case '6':
      return "mno";
    case '7':
      return "pqrs";
    case '8':
      return "tuv";
    case '9':
      return "wxyz";
    default:
      return "";
    }
  }
  void print_array(vector<string> v)
  {
    for (int i = 0; i < v.size(); i++)
    {
      cout << v[i] << ", ";
    }
    cout << endl;
  }
  vector<string> letterCombinations(string digits)
  {
    vector<string> solution;
    if (digits.length() == 0)
    {
      return solution;
    }
    backtrack(digits, 0, "", solution);
    return solution;
  }

  void backtrack(string digits, int currentIndex, string currentCombination, vector<string> &combinations)
  {
    if (currentIndex == digits.size())
    {
      combinations.push_back(currentCombination);
    }
    else
    {
      string letters = getNumberString(digits[currentIndex]);
      for (int i = 0; i < letters.length(); i++)
      {
        backtrack(digits, currentIndex + 1, currentCombination + letters[i], combinations);
      }
    }
  }
};

int main()
{
  Solution s;
  s.letterCombinations("22");
  return 0;
}