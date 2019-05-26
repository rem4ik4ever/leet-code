#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows == 1)
    {
      return s;
    }
    bool down = false;
    vector<string> rows(min(numRows, int(s.size())));
    int current = 0;
    for (char ch : s)
    {
      rows[current] += ch;
      if (current == 0 || current == numRows - 1)
      {
        down = !down;
      }
      current += down ? 1 : -1;
    }
    string res;
    for (string st : rows)
    {
      res += st;
    }
    return res;
  }
};

int main()
{
  Solution s;
  cout << s.convert("PAYPALISHIRING", 3) << endl;
  return 0;
}
