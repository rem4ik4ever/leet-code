#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

/**
 * 
 * Bitset arrray representation of bit string
 * 
 * */
class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    bitset<32> b = (bitset<32>)n;
    bitset<32> ans;
    for (int i = 0; i < 32; ++i)
    {
      ans[i] = b[b.size() - 1 - i];
    }

    return ans.to_ulong();
  }
};

int main()
{
  Solution s;
  cout << s.reverseBits(123) << endl;
  return 0;
}
