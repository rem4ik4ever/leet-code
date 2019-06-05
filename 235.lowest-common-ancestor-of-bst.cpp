#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 
 * Complexity O(H) where H is tree height
 * Space O(1) no space
 * 
 * Runtime: 32 ms, faster than 98.12% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
 * Memory Usage: 25.9 MB, less than 14.17% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
 * 
 * */
class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    while (true)
    {
      if ((p->val <= root->val && q->val >= root->val) || (p->val >= root->val && q->val <= root->val))
      {
        return root;
      }
      if (p->val > root->val && q->val > root->val)
      {
        root = root->right;
      }
      else
      {
        root = root->left;
      }
    }
  }
};

int main()
{
  Solution s;
  // s.lowestCommonAncestor()
  return 0;
}