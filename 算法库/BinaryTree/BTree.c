#define _CRT_SECURE_NO_WARNINGS 1
#include "BTree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	root->data = a[*pi];
	(*pi)++;
	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);
	return root;
}

void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->left));
	BinaryTreeDestory(&((*root)->right));
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}


int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* ret1 = BinaryTreeFind(root->left, x);
	BTNode* ret2 = BinaryTreeFind(root->right, x);
	return ret1 != NULL ? ret1 : ret2;
}

void BinaryTreeOrder(BTNode* root, int mode)
{
	if (root == NULL)
	{
		return;
	}
	if (mode == 0)
	{
		printf("%c ", root->data);
	}
	BinaryTreeOrder(root->left, mode);
	if (mode == 1)
	{
		printf("%c ", root->data);
	}
	BinaryTreeOrder(root->right, mode);
	if (mode == 2)
	{
		printf("%c ", root->data);
	}
}

void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	queue qu;
	queueinit(&qu);
	queuepush(&qu, root);
	while (!queueempty(&qu))
	{
		BTNode* tmp = queuefront(&qu);
		queuepop(&qu);
		printf("%c ", tmp->data);
		if (tmp->left)
		{
			queuepush(&qu, tmp->left);
		}
		if (tmp->right)
		{
			queuepush(&qu, tmp->right);
		}
	}
	printf("\n");
	queuedestroy(&qu);
}

int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	queue qu;
	queueinit(&qu);
	queuepush(&qu, root);
	int flag = 1;
	while (!queueempty(&qu))
	{
		BTNode* tmp = queuefront(&qu);
		queuepop(&qu);
		if (tmp)
		{
			if (flag == 0)
			{
				return 0;
			}
			queuepush(&qu, tmp->left);
			queuepush(&qu, tmp->right);
		}
		else
		{
			flag = 0;
		}
	}
	queuedestroy(&qu);
	return 1;
}