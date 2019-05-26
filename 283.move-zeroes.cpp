#include <iostream>
#include <vector>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

/**
 * 
 * Solution with O(1) space and O(N^2) complexity
 * Runtime: 32 ms, faster than 7.89% of C++ online submissions for Move Zeroes.
 * Memory Usage: 9.5 MB, less than 43.89% of C++ online submissions for Move Zeroes.
 * 
 * 
 * */
class Solution
{
public:
  void moveZeroes1(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
      {
        for (int j = i + 1; j < nums.size(); j++)
        {
          nums[j - 1] = nums[j];
        }
        nums[nums.size() - 1] = 0;
        --i;
        --n;
      }
    }
  }

  /**
   * Using more space but linear time
   * 
   * Space O(N) N size of array
   * Complexity O(N) N number if items in array
   * 
   * Runtime: 16 ms, faster than 94.23% of C++ online submissions for Move Zeroes.
   * Memory Usage: 9.6 MB, less than 30.52% of C++ online submissions for Move Zeroes.
   * 
   * */
  void moveZeroes(vector<int> &nums)
  {
    vector<int> res(nums.size(), 0);
    int currentIdx = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (nums[i] != 0)
      {
        res[currentIdx] = nums[i];
        ++currentIdx;
      }
    }
    nums = res;
  }
};

int main()
{
  Solution s;
  vector<int> v = {0, 1, 0, 3, 12};
  cout << s.moveZeroes(v) << endl;
  return 0;
}
