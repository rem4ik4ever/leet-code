#include <iostream>

using namespace std;

/**
 * 
 * Solution compare to 1 and shift by 1 bit for 32 times.
 * 
 * Everytime it value 
 * 
 * 
 * */
class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    int count = 0;
    for (int i = 0; i < 32; ++i)
    {
      if ((n & (1 << i)))
      {
        ++count;
      }
    }
    return count;
  }
};

int main()
{

  return 0;
}