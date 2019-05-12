
#include <iostream>
#include <sstream>
using namespace std;

/**
 * 
 * 
 * Runtime: 56 ms, faster than 41.84% of C++ online submissions for Construct Binary Tree from String.
 * Memory Usage: 26.5 MB, less than 33.33% of C++ online submissions for Construct Binary Tree from String.
 * 
 * 
 * */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
  TreeNode *str2tree(string s)
  {
    if (s.length() == 0)
    {
      return NULL;
    }
    int st = 0;
    stringstream str;
    while (s[st] != '(' && st < s.length())
    {
      str << s[st];
      ++st;
    }
    str << s[st];
    int root;
    str >> root;

    TreeNode *rootNode = new TreeNode(root);
    int count = 0;

    bool leftNode = false;
    for (int i = st; i < s.length(); i++)
    {
      if (s[i] == '(')
        ++count;
      else if (s[i] == ')')
        --count;

      // complete node string found
      if (count == 0)
      {
        if (!leftNode)
        {
          leftNode = true;
          rootNode->left = str2tree(s.substr(st + 1, i - st - 1));
          st = i + 1;
        }
        else
        {
          // building right node
          rootNode->right = str2tree(s.substr(st + 1, i - st - 1));
        }
      }
    }
    return rootNode;
  }
};

int main()
{

  Solution s;
  TreeNode *res = s.str2tree("-433(12)(2)");
  return 0;
}