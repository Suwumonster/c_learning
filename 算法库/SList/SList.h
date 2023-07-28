#pragma once
#include <stdio.h>
#include <malloc.h>
typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* phead);
// ������β��
void SListPushBack(SListNode** pphead, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pphead, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pphead);
// ������ͷɾ
void SListPopFront(SListNode** pphead);
// ���������
SListNode* SListFind(SListNode* phead, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������
void SListDestroy(SListNode* phead);
