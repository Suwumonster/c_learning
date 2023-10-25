#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (p == NULL || q == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return NULL;
    }
    struct TreeNode* newleft = invertTree(root->right);
    struct TreeNode* newright = invertTree(root->left);
    root->left = newleft;
    root->right = newright;
    return root;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    struct TreeNode* tmp = invertTree(root->right);
    return isSameTree(tmp, root->left);
}