#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

LTNode* LTinit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void LTDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTErase(cur);
		cur = phead->next;
	}
	free(phead);
}

LTNode* LTBuyNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->val = x;
	return newnode;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void LTPushBack(LTNode* phead, LTDateType x)
{
	//第一种
	//assert(phead);
	//LTNode* last = phead->prev;
	//LTNode* newnode = LTBuyNode(x);
	////last newnode phead
	//last->next = newnode;
	//newnode->prev = last;
	//newnode->next = phead;
	//phead->prev = newnode;
	//
	// 第二种 复用
	//
	LTInsert(phead, x);
}

void LTTopBack(LTNode* phead)
{
	// 第一种
	//assert(phead);
	//assert(phead->next != phead);
	//LTNode* last = phead->prev->prev;
	//LTNode* del = phead->prev;
	//free(del);
	//phead->prev = last;
	//last->next = phead;
	// 第二种 复用
	assert(phead->next != phead);
	LTErase(phead->prev);
}

void LTPushFront(LTNode* phead, LTDateType x)
{
	// 第一种
	//assert(phead);
	//LTNode* newnode = LTBuyNode(x);
	//LTNode* first = phead->next;
	////phead newnode first
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = first;
	//first->prev = newnode;
	// 第二种
	LTInsert(phead->next, x);
}

void LTTopFront(LTNode* phead)
{
	// 第一种
	//assert(phead);
	//assert(phead->next != phead);
	//LTNode* del = phead->next;
	//LTNode* first = del->next;
	////phead del first
	//free(del);
	//phead->next = first;
	//first->prev = phead;
	// 第二种
	assert(phead->next != phead);
	LTErase(phead->next);
}

LTNode* LTFind(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void LTInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = LTBuyNode(x);
	//prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}