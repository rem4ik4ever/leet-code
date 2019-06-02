/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    map<int, vector<int>, greater<int>> mp;
    vector<vector<int>> result;
    int level = 0;
    levelOrderPrint(root, mp, level);
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
      result.push_back(it->second);
    }

    return result;
  }

  void levelOrderPrint(TreeNode *root, map<int, vector<int>, greater<int>> &mp, int level)
  {
    if (root == NULL)
    {
      return;
    }

    levelOrderPrint(root->left, mp, level + 1);
    mp[level].push_back(root->val);
    levelOrderPrint(root->right, mp, level + 1);
  }
};