#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdbool.h>

// ******************************
// ���ߣ�suwu
// ����޸�ʱ�䣺2023/10/11 15:18
// ******************************

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


void queueinit(queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void queuedestroy(queue* pq)
{
	assert(pq);
	queuenode* cur = pq->head;
	while (cur)
	{
		queuenode* del = cur;
		cur = cur->next;
		free(del);
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void queuepush(queue* pq, QUDataType x)
{
	assert(pq);
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = (queuenode*)malloc(sizeof(queuenode));
		if (pq->head == NULL)
		{
			perror("malloc fail");
			exit(-1);
		}
		pq->head->val = x;
		pq->head->next = NULL;

	}
	else
	{
		queuenode* newnode = (queuenode*)malloc(sizeof(queuenode));
		if (newnode == NULL)
		{
			perror("malloc fail");
			exit(-1);
		}
		newnode->val = x;
		newnode->next = NULL;
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

void queuepop(queue* pq)
{
	assert(pq);
	assert(!queueempty(pq));
	queuenode* del = pq->head;
	pq->head = pq->head->next;
	free(del);
	if (pq->head == NULL)//����tailָ��Ұָ��
	{
		pq->tail = NULL;
	}
	pq->size--;
}

QUDataType queuefront(queue* pq)
{
	assert(pq);
	assert(!queueempty(pq));
	return pq->head->val;
}

QUDataType queueback(queue* pq)
{
	assert(pq);
	assert(!queueempty(pq));
	return pq->tail->val;
}

bool queueempty(queue* pq)
{
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}
int queuesize(queue* pq)
{
	assert(pq);
	return pq->size;
}

typedef struct {
	queue q1;
	queue q2;
} MyStack;

bool myStackEmpty(MyStack* obj);

MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	queueinit(&st->q1);
	queueinit(&st->q2);
	return st;
}

void myStackPush(MyStack* obj, int x) {
	assert(obj);
	if (!queueempty(&obj->q1))
	{
		queuepush(&obj->q1, x);
	}
	else
	{
		queuepush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj)
{
	assert(obj);
	assert(!myStackEmpty(obj));
	int ret = myStackTop(obj);
	queuenode* emptyqu = &obj->q1;
	queuenode* nonemptyqu = &obj->q2;
	if (!queueempty(emptyqu))
	{
		emptyqu = &obj->q2;
		nonemptyqu = &obj->q1;
	}
	while (queuesize(nonemptyqu) > 1)
	{
		queuepush(emptyqu, queuefront(nonemptyqu));
		queuepop(nonemptyqu);
	}
	queuepop(nonemptyqu);
	return ret;
}

int myStackTop(MyStack* obj)
{
	assert(obj);
	assert(!myStackEmpty(obj));
	queuenode* emptyqu = &obj->q1;
	queuenode* nonemptyqu = &obj->q2;
	if (!queueempty(emptyqu))
	{
		emptyqu = &obj->q2;
		nonemptyqu = &obj->q1;
	}
	return queueback(nonemptyqu);
}

bool myStackEmpty(MyStack* obj)
{
	assert(obj);
	return queueempty(&obj->q1) && queueempty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	assert(obj);
	queuedestroy(&obj->q1);
	queuedestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/