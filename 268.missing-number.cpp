#include <iostream>
#include <vector>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

/**
 * 
 * Using Additional space to increase Speed
 * 
 * Complexity O(N) constant time
 * Space O(N) additional array to store size
 * 
 * */
class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    if (nums.size() == 0)
    {
      return 0;
    }
    vector<int> place(nums.size() + 1, -1);
    for (int i = 0; i < nums.size(); ++i)
    {
      place[nums[i]] = nums[i];
    }
    for (int i = 0; i < nums.size() + 1; ++i)
    {
      if (place[i] == -1)
      {
        return i;
      }
    }
    return 0;
  }
};

int main()
{
  Solution s;
  vector<int> v = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  cout << s.missingNumber(v) << endl;
  return 0;
}
