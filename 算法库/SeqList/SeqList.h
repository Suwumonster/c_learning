//*********************************
// ���ߣ�suwu
// ����: vs2019 win10
// ����޸�ʱ�䣺2023/7/21 15:50
//*********************************
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;//˳�����һ���洢��Ԫ���������ͣ������޸ģ�ֻ���ڴ˰�int�޸�Ϊ������������

// �Զ���˳�������ݽṹ
typedef struct SeqList
{
	SLDateType* a;//˳�������
	int size;//���д洢���ݸ���
	int capacity;//˳�������
}SeqList;

// �����ݵĹ���:��ɾ��� 

// �������ƣ�SeqListInit
// �������ܣ���ʼ��˳���Ϊ˳�������ռ䣬˳���������ʼ��Ϊ3����
// ����������˳���ָ��ps
// �������ͼ����ݣ���
void SeqListInit(SeqList* ps);//��ʼ��

// �������ƣ�SeqListDestroy
// �������ܣ�����˳����ͷ�˳���������Ŀռ䣬����ָ���ÿա�
// ����������˳���ָ��ps
// �������ͼ����ݣ���
void SeqListDestroy(SeqList* ps);//����

// �������ƣ�SeqListPrint
// �������ܣ���˳����������ŷ�˳���ӡ���ݡ�
// ����������˳���ָ��ps
// �������ͼ����ݣ���
void SeqListPrint(SeqList* ps);//��ӡ

// ˳������
// �������ƣ�SeqListFind
// �������ܣ�����˳�����������ݣ���x��ͬ�ĵ�һ�����ݵ��±꽫�����ء�
// ����������˳���ָ��ps���ȶ�����x
// �������ͼ����ݣ���x��ͬ�ĵ�һ�����ݵ��±꣬���û�ҵ�����˳���ָ��psΪ���򷵻�-1
int SeqListFind(SeqList* ps, SLDateType x);

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos);

void SeqListPushBack(SeqList* ps, SLDateType x);//��壬���Կ���Insert����ʵ�֡�
void SeqListPushFront(SeqList* ps, SLDateType x);//ǰ�壬���Կ���Insert����ʵ�֡�
void SeqListPopFront(SeqList* ps);//��ɾ�����Կ���Erase����ʵ�֡�
void SeqListPopBack(SeqList* ps);//ǰɾ�����Կ���Erase����ʵ�֡�





