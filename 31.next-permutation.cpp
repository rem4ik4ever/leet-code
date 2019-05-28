#include <iostream>
#include <vector>

using namespace std;

// Not solved :(
// Solved :)

// Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
// Find the largest index l > k such that nums[l] > nums[k].
// Swap nums[k] and nums[l].
// Reverse the sub-array nums[k + 1:].
class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int k, n = nums.size(), l;

    for (k = nums.size() - 2; k >= 0; --k)
    {
      if (nums[k] < nums[k + 1])
      {
        break;
      }
    }
    if (k < 0)
    {
      reverse(nums.begin(), nums.end());
    }
    else
    {
      for (l = n - 1; l > k; --l)
      {
        if (nums[l] > nums[k])
        {
          break;
        }
      }
      swap(nums[l], nums[k]);
      reverse(nums.begin() + k + 1, nums.end());
    }
  }
};

void print_array(vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    if (i > 0)
      cout << ", ";
    cout << v[i];
  }
  cout << endl;
}
int main()
{
  Solution s;
  vector<int> input = {1, 2, 3};
  s.nextPermutation(input);
  print_array(input);
  return 0;
}