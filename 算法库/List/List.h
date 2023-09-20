#pragma once
//
//*************************
// ���ߣ�suwu
// ����޸����ڣ�2023/9/20 19:00
// ������win10 vs2019
// ************************
//
#include <stdio.h>
#include <assert.h>

//���������ݴ洢����
typedef int LTDateType;

// ˫���ͷѭ������ �ṹ��
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDateType val;
}LTNode;

//��ʼ��
// �������ƣ�LTinit
// �������ܣ���ʼ��LT������һ���ڱ����ڵ㣬���ڱ���ָ�붼ָ���Լ�
// ������������
// �������ͼ����ݣ�����һ���ڱ����ڵ�
LTNode* LTinit();

//����
// �������ƣ�LTDestory
// �������ܣ�����LT���Ѱ����ڱ����ڵ��������нڵ㶼����
// ���������������ڱ����ڵ�
// �������ͼ����ݣ���
void LTDestory(LTNode* phead);

//����ڵ�
// �������ƣ�LTBuyNode
// �������ܣ���������x������һ��LT�ڵ㣬������
// ��������������洢����x
// �������ͼ����ݣ���������õ�LT�ڵ�
LTNode* LTBuyNode(LTDateType x);

//��ӡ�ڵ�
// �������ƣ�LTPrint
// �������ܣ���ӡLT���нڵ������
// �����������ڱ����ڵ�
// �������ͼ����ݣ���
void LTPrint(LTNode* phead);

//β��
// �������ƣ�LTPushBack
// �������ܣ���LT����β������һ���洢����x�Ľڵ�
// �����������ڱ����ڵ㣬����x
// �������ͼ����ݣ���
void LTPushBack(LTNode* phead, LTDateType x);

//βɾ
// �������ƣ�LTTopBack
// �������ܣ�ɾ��LT����β��һ���ڵ�
// �����������ڱ����ڵ�
// �������ͼ����ݣ���
void LTTopBack(LTNode* phead);

//ͷ��
// �������ƣ�LTPushFront
// �������ܣ���LT����ͷ������һ���洢����x�Ľڵ�
// �����������ڱ����ڵ㣬����x
// �������ͼ����ݣ���
void LTPushFront(LTNode* phead, LTDateType x);

//ͷɾ
// �������ƣ�LTTopFront
// �������ܣ�ɾ��LT����ͷ��һ���ڵ�
// �����������ڱ����ڵ�
// �������ͼ����ݣ���
void LTTopFront(LTNode* phead);

//���ҽڵ�
// �������ƣ�LTFind
// �������ܣ�����������x��ͬ�Ľڵ㲢���ص�ַ
// �����������ڱ����ڵ㣬����x
// �������ͼ����ݣ�������x��ͬ�Ľڵ��ַ
LTNode* LTFind(LTNode* phead, LTDateType x);


//��pos�ڵ�ǰ�����
// �������ƣ�LTInsert
// �������ܣ���pos�ڵ�֮ǰ����һ������x���½ڵ�
// ����������pos�ڵ㣬����x
// �������ͼ����ݣ���
void LTInsert(LTNode* pos, LTDateType x);


//ɾ��pos�ڵ�
// �������ƣ�LTErase
// �������ܣ�ɾ��pos�ڵ�
// ����������pos�ڵ�
// �������ͼ����ݣ���
void LTErase(LTNode* pos);