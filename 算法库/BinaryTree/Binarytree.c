#define _CRT_SECURE_NO_WARNINGS 1
#include "Binarytree.h"

BT* BTBuyNode(BTDataType x)
{
	BT* tmp = (BT*)malloc(sizeof(BT));
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	tmp->val = x;
	for (int i = 0; i < N; i++)
	{
		tmp->child[i] = NULL;
	}
	return tmp;
}

void visit(BT* cur)
{
	if (cur == NULL)
	{
		return;
	}
	printf("%d ", cur->val);
}

void BTorder(BT* root, int mode)
{
	if (root == NULL)
	{
		return;
	}
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (i == mode)
		{
			visit(root);
		}
		BTorder(root->child[i], mode);
	}
	if (i == mode)
	{
		visit(root);
	}
}

int BTNodesum(BT* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += BTNodesum(root->child[i]);
	}
	return sum + 1;
}

int BTLeaveNodesum(BT* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int flag = 1;
	for (int i = 0; i < N; i++)
	{
		if (root->child[i] != NULL)
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		return 1;
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += BTLeaveNodesum(root->child[i]);
	}
	return sum;
}

int BTHeight(BT* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		int tmp = BTHeight(root->child[i]);
		if (tmp > max)
		{
			max = tmp;
		}
	}
	return 1 + max;
}

int BTLayerNodesum(BT* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += BTLayerNodesum(root->child[i], k - 1);
	}
	return sum;
}