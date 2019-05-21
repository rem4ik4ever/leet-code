#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 * */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 
 * 
 * Complexity O(N) where N is number of nodes
 * Space O(N) where N is size of Array with all nodes
 * 
 * Runtime: 4 ms, faster than 95.90% of C++ online submissions for Binary Tree Inorder Traversal.
 * Memory Usage: 9.4 MB, less than 29.72% of C++ online submissions for Binary Tree Inorder Traversal.
 * 
 *  
 * */
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};

int main()
{
    Solution s;
    // s.inorderTraversal();
    return 0;
}