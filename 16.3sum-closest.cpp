#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Not Solved :(

void reverse(vector<int> v)
{
  for (int i = 0, j = v.size() - 1; i < j; i++, --j)
  {
    swap(v[i], v[j]);
  }
}

void print_array(vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << ", ";
  }
  cout << endl;
}

void printMatrix(vector<vector<int>> matrix)
{
  for (int i = 0; i < matrix.size(); i++)
  {
    cout << "[ ";
    for (int j = 0; j < matrix[i].size(); j++)
    {
      if (j > 0)
      {
        cout << ", ";
      }
      cout << matrix[i][j];
    }
    cout << " ]" << endl;
  }
}

class Solution
{
public:
  void print_array(vector<int> v)
  {
    for (int i = 0; i < v.size(); i++)
    {
      cout << v[i] << ", ";
    }
    cout << endl;
  }

  int threeSumClosest(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    int solution = 2147483647;
    for (int i = 0; i < nums.size(); i++)
    {
      if (i > 0 && nums[i - 1] == nums[i])
      {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right)
      {
        int sum = abs(nums[left] + nums[right] + nums[i]);
        solution = abs(solution - target) < abs(sum - target) ? solution : sum;
        if (left < right && sum < target)
        {
          ++left;
        }
        else if (left < right && sum > target)
        {
          --right;
        }
        else
        {
          return target;
        }
      }
    }
    return solution;
  }
};

int main()
{
  Solution s;
  vector<int> input = {0, 2, 1, -3};
  cout << s.threeSumClosest(input, 1) << endl;
  return 0;
}