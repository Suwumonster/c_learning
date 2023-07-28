#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


// 单链表打印
void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// 单链表尾插
void SListPushBack(SListNode** pphead, SLTDateType x)
{
	if (*pphead == NULL)
	{
		*pphead = BuySListNode(x);
	}
	else
	{
		SListNode* newnode = BuySListNode(x);
		SListNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

// 单链表的尾删
void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)//链表为空
	{
		return;
	}
	SListNode* prev = *pphead;
	SListNode* cur = (*pphead)->next;
	if (cur == NULL)//链表只有一个节点
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	while (cur->next != NULL)//一般情况
	{
		prev = prev->next;
		cur = cur->next;
	}
	free(cur);
	prev->next = 0;
}


// 单链表的头插
void SListPushFront(SListNode** pphead, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

// 单链表头删
void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SListNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}


// 单链表查找
SListNode* SListFind(SListNode* phead, SLTDateType x)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
	{
		perror("InsertAfter fail!");
		exit(-1);
	}
	SListNode* prev = pos;
	SListNode* cur = pos->next;
	SListNode* newnode = BuySListNode(x);
	prev->next = newnode;
	newnode->next = cur;
}


// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL)
	{
		perror("EraseAfter fail!");
		exit(-1);
	}
	SListNode* tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = pos->next->next;
	free(tmp);
}


// 单链表的销毁
void SListDestroy(SListNode* phead)
{
	if (phead == NULL)
	{
		return;
	}
	SListNode* prev = phead;
	SListNode* cur = phead->next;
	while (cur != NULL)
	{
		free(prev);
		prev = cur;
		cur = cur->next;
	}
	free(prev);
}