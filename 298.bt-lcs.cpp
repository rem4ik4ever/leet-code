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

// Runtime: 48 ms, faster than 88.47% of C++ online submissions for Binary Tree Longest Consecutive Sequence.
// Memory Usage: 28 MB, less than 72.76% of C++ online submissions for Binary Tree Longest Consecutive Sequence.
class Solution
{
public:
    int longestConsecutive(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int maxLCS = 0;
        traverseAndCheck(root, NULL, maxLCS, 0);
        return maxLCS;
    }

    void traverseAndCheck(TreeNode *root, TreeNode *parent, int &maxLCS, int length)
    {
        if (root == NULL)
            return;
        length = (parent != NULL && root->val == parent->val + 1) ? length + 1 : 1;
        maxLCS = max(maxLCS, length);
        traverseAndCheck(root->left, root, maxLCS, length);
        traverseAndCheck(root->right, root, maxLCS, length);
    }
};

int main()
{
    Solution s;
    // s.longestConsecutive();
    return 0;
}