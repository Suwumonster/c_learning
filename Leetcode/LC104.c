#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



int maxDepth(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	int ret1, ret2 = 0;
	ret1 = maxDepth(root->left);
	ret2 = maxDepth(root->right);

	return ret1 > ret2 ? ret1 + 1 : ret2 + 1;
}