

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    stack<char> st;
    int max = 0;
    for (int i = 0; i < s.length; i++)
    {
      if (s[i] == '(')
      {
        st.push(s[i]);
        while (st.size() != 0)
        {
        }
      }
    }
  }
};

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

int main()
{

  return 0;
}