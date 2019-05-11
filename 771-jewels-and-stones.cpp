#include <iostream>
#include <string.h>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int numJewelsInStones(string J, string S) {
      unordered_map<char, int> umap;
      umap.reserve(J.length());
      int result = 0;
      for (string::iterator i = J.begin(); i != J.end(); i++)
      {
        umap[*i] = 0;
      }
      for (string::iterator i = S.begin(); i != S.end(); i++)
      {
        if(umap.find(*i) != umap.end()) 
        {
          result += 1; 
        }
      }

      return result;
    }
};



int main() 
{
  Solution s;
  int result = s.numJewelsInStones("c", "aAAbbbb");
  cout << result << endl;
  return 0;
}