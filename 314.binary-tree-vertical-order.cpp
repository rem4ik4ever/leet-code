#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <iterator>

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
class Solution
{
public:
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        int position = 0;
        map<int, multimap<int, int>> res;
        verticalPrint(root, res, position, 0);
        for (auto positionIter = res.begin(); positionIter != res.end(); ++positionIter)
        {
            vector<int> tmp;
            for (auto orderIter = positionIter->second.begin(); orderIter != positionIter->second.end(); ++orderIter)
            {
                tmp.push_back(orderIter->second);
            }
            result.push_back(tmp);
        }
        return result;
    }

    void verticalPrint(TreeNode *root, map<int, multimap<int, int>> &result, int position, int depth)
    {

        if (root == NULL)
        {
            return;
        }
        result[position].insert(make_pair(depth, root->val));
        verticalPrint(root->left, result, position - 1, depth + 1);
        verticalPrint(root->right, result, position + 1, depth + 1);
    }
};