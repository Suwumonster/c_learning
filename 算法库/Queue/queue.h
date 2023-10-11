#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef int QUDataType;//�����ڴ洢��������

//��ʽ���нڵ�ṹ
typedef struct QUEUENODE
{
	QUDataType val;
	struct QUEUENODE* next;
}queuenode;

//���нṹ
typedef struct QUEUE
{
	queuenode* head;
	queuenode* tail;
	int size;
}queue;

// ��������queueinit
// �������ܣ���ʼ�����У�������ָ���ÿգ�size��0
// ��������������ָ��
// �����������ͼ����ݣ���
void queueinit(queue* pq);

// ��������queuedestroy
// �������ܣ����ٶ��У�����������Ŀռ�ȫ�����٣�ָ���ÿգ�size��0
// ��������������ָ��
// �����������ͼ����ݣ���
void queuedestroy(queue* pq);

// ��������queuepush
// �������ܣ���ӣ�������x�����β
// ��������������ָ�룬����x
// �����������ͼ����ݣ���
void queuepush(queue* pq, QUDataType x);

// ��������queuepop
// �������ܣ����ӣ��Ѷ�ͷ��һ������ɾ������
// ��������������ָ��
// �����������ͼ����ݣ���
void queuepop(queue* pq);

// ��������queuefront
// �������ܣ�ȡ��ͷ��һ������
// ��������������ָ��
// �����������ͼ����ݣ�QUDataType����ͷ����
QUDataType queuefront(queue* pq);

// ��������queueback
// �������ܣ�ȡ��β��һ������
// ��������������ָ��
// �����������ͼ����ݣ�QUDataType����β����
QUDataType queueback(queue* pq);

// ��������queueempty
// �������ܣ��ж϶����Ƿ�Ϊ��
// ��������������ָ��
// �����������ͼ����ݣ�bool������
bool queueempty(queue* pq);

// ��������queuesize
// �������ܣ��������������ݸ���
// ��������������ָ��
// �����������ͼ����ݣ�int�����������ݸ���
int queuesize(queue* pq);