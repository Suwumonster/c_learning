//*********************************
// ���ߣ�suwu
// ����: vs2019 win10
// ����޸�ʱ�䣺2023/7/23 15:51
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
int SeqListFind1(SeqList* ps, SLDateType x);

// �������ƣ�SeqListFind
// �������ܣ���begin�±�λ�ÿ�ʼ����˳�����������ݣ���x��ͬ�ĵ�һ�����ݵ��±꽫�����ء�
//			 ���whileѭ�����԰�������xֵ��ͬ������ɾ��
// ����������˳���ָ��ps���ȶ�����x����ʼ�����±�begin
// �������ͼ����ݣ���x��ͬ�ĵ�һ�����ݵ��±꣬���û�ҵ�����˳���ָ��psΪ���򷵻�-1
int SeqListFind2(SeqList* ps, SLDateType x, int begin);

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, int pos);




void SeqListPushBack(SeqList* ps, SLDateType x);//β�壬���Կ���Insert����ʵ�֡�
void SeqListPushFront(SeqList* ps, SLDateType x);//ͷ�壬���Կ���Insert����ʵ�֡�
void SeqListPopFront(SeqList* ps);//ͷɾ�����Կ���Erase����ʵ�֡�
void SeqListPopBack(SeqList* ps);//βɾ�����Կ���Erase����ʵ�֡�