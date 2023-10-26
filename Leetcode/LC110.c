#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int TreeHeight(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ret1 = TreeHeight(root->left);
    int ret2 = TreeHeight(root->right);
    return ret1 > ret2 ? ret1 + 1 : ret2 + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    int h1 = TreeHeight(root->left);
    int h2 = TreeHeight(root->right);
    if (abs(h1 - h2) > 1)
    {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}