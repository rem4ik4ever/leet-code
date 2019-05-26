#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
    int longestConsecutive(TreeNode *root)
    {
        int maxLCS = 0;
        inorder(root, NULL, 0, maxLCS);
        return maxLCS;
    }

    int inorder(TreeNode *root, TreeNode *parent, int length)
    {
        if (root == NULL)
        {
            return;
        }
        if (parent != NULL && (root->val + 1 == parent->val || root->val + 1 == parent->val + 1))
        {
            length += 1;
            maxLCS = max(length, maxLCS);
        }
        else
        {
            length = 0;
        }
        inorder(root->left, root, length);
        inorder(root->right, root, length);
    }
};
