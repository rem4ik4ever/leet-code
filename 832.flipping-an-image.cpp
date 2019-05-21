#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
  {
    for (int i = 0; i < A.size(); i++)
    {
      A[i] = flip(A[i]);
    }
    return A;
  }
  vector<int> flip(vector<int> &v)
  {
    vector<int> flipped(v.size(), 0);
    for (int i = 0; i < v.size(); i++)
    {
      flipped[v.size() - i - 1] = abs(v[i] - 1);
    }
    return flipped;
  }
};

int mina()
{
  Solution s;
  vector<vector<int>> v = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};

  return 0;
}