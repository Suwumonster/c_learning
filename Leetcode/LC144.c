#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void PrevOrder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    a[*pi] = root->val;
    (*pi)++;
    PrevOrder(root->left, a, pi);
    PrevOrder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    PrevOrder(root, a, &i);
    return a;
}