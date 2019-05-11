#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * 
 * 
 * Runtime: 52 ms, faster than 83.06% of C++ online submissions for Binary Search.
 * Memory Usage: 11 MB, less than 86.63% of C++ online submissions for Binary Search.
 * 
 * 
 * Complexity O(LogN)
 * Space O(N)
 * 
 * */
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int mid = 0;
    int start = 0, end = nums.size() - 1;
    int found = -1;
    while (start <= end && found == -1)
    {
      mid = (start + end) / 2;
      if (nums[mid] == target)
      {
        return found = mid;
      }
      else if (nums[mid] > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    return found;
  }
};

int main()
{
  Solution s;
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
  s.search(v, 3);
  return 0;
}