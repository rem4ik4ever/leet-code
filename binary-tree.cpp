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

void add(TreeNode *rootNode, int val)
{
    TreeNode *current = rootNode;
    bool placed = false;
    while (!placed)
    {
        if (val < current->val)
        {
            if (current->left != NULL)
            {
                current = current->left;
            }
            else
            {
                current->left = new TreeNode(val);
                placed = true;
            }
        }
        else
        {
            if (current->right != NULL)
            {
                current = current->right;
            }
            else
            {
                current->right = new TreeNode(val);
                placed = true;
            }
        }
    }
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void fill(TreeNode *rootNode)
{
    add(rootNode, 10);
    add(rootNode, 20);
    add(rootNode, 8);
    add(rootNode, 12);
    add(rootNode, 17);
    add(rootNode, 25);
    add(rootNode, 6);
    add(rootNode, 11);
    add(rootNode, 16);
    add(rootNode, 27);
}

TreeNode *findNode(TreeNode *rootNode, int val)
{
    if (rootNode == NULL)
    {
        return NULL;
    }
    if (rootNode->val == val)
    {
        return rootNode;
    }
    if (val < rootNode->val)
    {
        return findNode(rootNode->left, val);
    }
    else
    {
        return findNode(rootNode->right, val);
    }
}

TreeNode *findMin(TreeNode *node)
{
    if (node == NULL)
        return NULL;
    if (node->left != NULL)
    {
        return findMin(node->left);
    }
    return node;
}

/**
 * 
 * Steps:
 * 1. Find Node by given Data assuming node exists or return NULL
 * 2. If node has right branch return Minimal value node from Right branch
 * 3. If node does not have right branch return its ancestor 
 *      By iterating from root and assigning ancesstor and successor
 *      if ancestor < current
 *          successor = ancestor
 *          ancestor = ancestor->left
 *      else 
 *          ancestor = ancestor->right
 *      
 *      repeat until ancestor != current
 *    
 * Complexity O(h) where h is height of tree
 * 
 * 
 * */
TreeNode *findSuccessor(TreeNode *rootNode, int val)
{
    TreeNode *current = findNode(rootNode, val);
    if (current == NULL)
    {
        return NULL;
    }
    if (current->right != NULL)
    {
        return findMin(current->right);
    }
    else
    {
        TreeNode *successor = NULL;
        TreeNode *ancestor = rootNode;
        while (ancestor != current)
        {
            if (current->val < ancestor->val)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

int main()
{
    TreeNode *rootNode = new TreeNode(15);
    fill(rootNode);
    inorder(rootNode);
    cout << endl;
    TreeNode *successor = findSuccessor(rootNode, 27);
    if (successor != NULL)
    {
        cout << "Successor: " << successor->val << endl;
    }
    else
    {
        cout << "No successor" << endl;
    }
    return 0;
}