#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 
 * Not solved :(
 * 
 * 
 * */
class Solution
{
public:
  string longestPalindrome(string s)
  {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return lcs(s, s2);
  }

  string lcs(string s1, string s2)
  {
    int n = s1.length();
    int m = s2.length();
    string dp[m + 1][n + 1];
    string maxStr = "";

    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
      {
        if (i == 0 || j == 0)
        {
          // dp[i][j] = ' ';
        }
        else if (s1[i - 1] == s2[j - 1])
        {
          dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
          if (maxStr.length() < dp[i][j].length())
          {
            maxStr = dp[i][j];
          }
        }
      }
    }
    return maxStr;
  }
};

int main()
{
  Solution s;
  cout << (s.longestPalindrome("abacda") == "aba" ? "True" : "False") << endl;
  cout << (s.longestPalindrome("abcda") == "a" ? "True" : "False") << endl;
  return 0;
}