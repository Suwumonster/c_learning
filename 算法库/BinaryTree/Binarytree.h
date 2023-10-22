#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// ******************************
// 作者：suwu
// 最后修改时间：2023/10/22 21:49
// ******************************
#define N 2 //定义孩子个数

typedef int BTDataType; //树储存数据的类型

typedef struct BinaryTree//树的节点
{
	BTDataType val;
	struct BinaryTree* child[N];
}BT;

// 函数名：BTBuyNode
// 函数功能：申请一个树节点，孩子指针全置空，把数据x存入，最后返回
// 函数参数：数据x
// 函数返回类型及内容：BT* 树节点 
BT* BTBuyNode(BTDataType x);

// 函数名：visit
// 函数功能：打印树节点的数据
// 函数参数：树节点指针
// 函数返回类型及内容：空 
void visit(BT* cur);

// 函数名：BTorder
// 函数功能：接受不同的mode值，执行不同的深度遍历  mode 0 1 2分别代表 前序 中序 后序
// 函数参数：树根指针，mode值
// 函数返回类型及内容：空 
void BTorder(BT* root, int mode);

// 函数名：BTNodesum
// 函数功能：算出树总的节点个数
// 函数参数：树根指针
// 函数返回类型及内容：int 树的节点个数
int BTNodesum(BT* root);

// 函数名：BTLeaveNodesum
// 函数功能：算出树的叶子节点个数
// 函数参数：树根指针
// 函数返回类型及内容：int 树的叶子节点个数
int BTLeaveNodesum(BT* root);

// 函数名：BTHeight
// 函数功能：算出树的高度/深度 树根算第1层
// 函数参数：树根指针
// 函数返回类型及内容：int 树的深度/高度
int BTHeight(BT* root);

// 函数名：BTLayerNodesum
// 函数功能：算出树第k层的节点个数
// 函数参数：树根指针
// 函数返回类型及内容：int 树的k层节点个数
int BTLayerNodesum(BT* root, int k);
