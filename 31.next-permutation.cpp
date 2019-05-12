#include <iostream>
#include <vector>

using namespace std;

// Not solved :(

class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int st = nums.size() - 1;
    while (st >= 0)
    {
      if (st - 1 >= 0)
      {
        if (nums[st] > nums[st - 1])
        {
          --st;
          break;
        }
        else
        {
          --st;
        }
      }
      else
      {
        --st;
      }
    }
    if (st < 0)
    {
      st = 0;
    }
    print_array(nums);

    reverse(nums, st);
  }

  void reverse(vector<int> &v, int start)
  {
    for (int i = start, j = v.size() - 1; i < j; i++, --j)
    {
      swap(v[i], v[j]);
    }
  }
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