#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findMaxForm(vector<string> &strs, int m, int n)
  {
    int res = 0;
    // res = dp(strs, 0, m, n);
    res = dp_iterative(strs, m, n);
    return res;
  }

  // Iterateive DP solution with memorization
  //
  int dp_iterative(vector<string> &strs, int m, int n)
  {
    int maxStrings = 0;
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
    int totalZ = m, totalO = n;
    for (int idx = 0; idx < strs.size(); ++idx)
    {
      int zeros = 0, ones = 0;
      // counting 1s and 0s
      for (int i = 0; i < strs[idx].size(); ++i)
      {
        if (strs[idx][i] == '1')
        {
          ++ones;
        }
        else
        {
          ++zeros;
        }
      }

      for (int i = m; i >= zeros; --i)
      {
        for (int j = n; j >= ones; --j)
        {
          memo[i][j] = max(memo[i][j], memo[i - zeros][j - ones] + 1);
        }
      }
    }
    return memo[m][n];
  }

  // Recursive DP solution
  // Time Limit Exceeded due to recursive call stack
  // Complexity O(N * 2^M*N) N number if words M = 0s N = 1s
  int dp(vector<string> &strs, int idx, int m, int n)
  {
    if (idx >= strs.size())
    {
      return 0;
    }
    int zeros = 0, ones = 0;
    for (int i = 0; i < strs[idx].size(); ++i)
    {
      if (strs[idx][i] == '1')
      {
        ++ones;
      }
      else
      {
        ++zeros;
      }
    }
    if (m - zeros >= 0 && n - ones >= 0)
    {
      return max(1 + dp(strs, idx + 1, m - zeros, n - ones), dp(strs, idx + 1, m, n));
    }
    else
    {
      return dp(strs, idx + 1, m, n);
    }
  }

  void print_array(vector<string> v)
  {
    for (int i = 0; i < v.size(); i++)
    {
      cout << v[i] << ' ';
    }
    cout << endl;
  }
};

int main()
{
  Solution s;
  vector<string> v = {"10", "0001", "111001", "1", "0"};

  cout << s.findMaxForm(v, 5, 3) << endl;
  return 0;
}