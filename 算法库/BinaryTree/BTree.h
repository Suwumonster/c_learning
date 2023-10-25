#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);

// 二叉树销毁
void BinaryTreeDestory(BTNode** root);

// 二叉树节点个数
int BinaryTreeSize(BTNode* root);

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 二叉树遍历 
void BinaryTreeOrder(BTNode* root, int mode);//mode 0 1 2 prev in post

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
