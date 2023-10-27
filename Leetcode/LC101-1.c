#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool _isSymmetric(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->val != root2->val)
    {
        return false;
    }
    return _isSymmetric(root1->left, root2->right) && _isSymmetric(root1->right, root2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    return _isSymmetric(root->left, root->right);
}