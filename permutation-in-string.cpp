#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * Runtime: 12 ms, faster than 93.23% of C++ online submissions for Permutation in String.
 * Memory Usage: 9.4 MB, less than 79.55% of C++ online submissions for Permutation in String.
 * 
 * 
 * */
class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    if (s1.size() > s2.size())
    {
      return false;
    }
    vector<int> s1_map(26, 0);
    vector<int> s2_map(26, 0);
    for (int i = 0; i < s1.length(); i++)
    {
      s1_map[s1[i] - 'a']++;
      s2_map[s2[i] - 'a']++;
    }
    if (s1_map == s2_map)
    {
      return true;
    }
    for (int i = 0; i < s2.length() - s1.length(); ++i)
    {
      if (s1_map == s2_map)
      {
        return true;
      }
      s2_map[s2[i + s1.length()] - 'a']++;
      s2_map[s2[i] - 'a']--;
    }
    return s1_map == s2_map;
  }

  void print_array(vector<int> v)
  {
    for (int i = 0; i < v.size(); i++)
    {
      cout << v[i] << ", ";
    }
    cout << endl;
  }
};

int main()
{
  Solution s;
  cout << s.checkInclusion("ab", "eidbaooo") << endl;
  return 0;
}