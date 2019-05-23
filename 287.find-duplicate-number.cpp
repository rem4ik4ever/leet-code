#include <iostream>
#include <vector>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

/**
 * 
 * Runtime: 12 ms, faster than 95.42% of C++ online submissions for Find the Duplicate Number.
 * Memory Usage: 10.1 MB, less than 15.08% of C++ online submissions for Find the Duplicate Number.
 * 
 * Complexity O(N)
 * Space O(N) N for an additional array to check duplicate values
 * 
 * */
class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    vector<int> memo(nums.size() + 1, 0);
    for (int num : nums)
    {
      ++memo[num];
      if (memo[num] > 1)
      {
        return num;
      }
    }
    return 0;
  }
};

int main()
{
  Solution s;
  vector<int> v = {1, 3, 4, 2, 2};
  cout << s.findDuplicate(v) << endl;
  return 0;
}
