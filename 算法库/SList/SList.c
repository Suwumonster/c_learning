#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

// ��̬����һ���ڵ�
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


// �������ӡ
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

// ������β��
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

// �������βɾ
void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)//����Ϊ��
	{
		return;
	}
	SListNode* prev = *pphead;
	SListNode* cur = (*pphead)->next;
	if (cur == NULL)//����ֻ��һ���ڵ�
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	while (cur->next != NULL)//һ�����
	{
		prev = prev->next;
		cur = cur->next;
	}
	free(cur);
	prev->next = 0;
}


// �������ͷ��
void SListPushFront(SListNode** pphead, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

// ������ͷɾ
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


// ���������
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

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
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


// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
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


// �����������
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