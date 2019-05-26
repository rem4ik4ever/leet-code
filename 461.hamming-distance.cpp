#include <iostream>

using namespace std;

/**
 * 
 * & AND operator only will return 1 on 1 or 0 on 0
 * 
 * << left shift operator
 * 
 * ^ XOR operator 1 only on not equal 1 and 0 comparison otherwise 0 
 * 
 * 
 * 
 * */
class Solution
{
public:
  int hammingDistance(int x, int y)
  {
    int count = 0;
    for (int i = 0; i < 32; ++i)
    {
      if ((x & (1 << i)) ^ (y & (1 << i)))
      {
        cout << ((x & (1 << i)) ^ (y & (1 << i))) << endl;
        ++count;
      }
    }
    return count;
  }
};

int main()
{
  Solution s;
  cout << s.hammingDistance(1, 4) << endl;
  return 0;
}