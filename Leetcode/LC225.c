#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdbool.h>

// ******************************
// 作者：suwu
// 最后修改时间：2023/10/11 15:18
// ******************************

typedef int QUDataType;//队列内存储数据类型

//链式队列节点结构
typedef struct QUEUENODE
{
	QUDataType val;
	struct QUEUENODE* next;
}queuenode;

//队列结构
typedef struct QUEUE
{
	queuenode* head;
	queuenode* tail;
	int size;
}queue;

// 函数名：queueinit
// 函数功能：初始化队列，队列内指针置空，size置0
// 函数参数：队列指针
// 函数返回类型及内容：空
void queueinit(queue* pq);

// 函数名：queuedestroy
// 函数功能：销毁队列，队列所申请的空间全部销毁，指针置空，size置0
// 函数参数：队列指针
// 函数返回类型及内容：空
void queuedestroy(queue* pq);

// 函数名：queuepush
// 函数功能：入队，把数据x插入队尾
// 函数参数：队列指针，数据x
// 函数返回类型及内容：空
void queuepush(queue* pq, QUDataType x);

// 函数名：queuepop
// 函数功能：出队，把队头的一个数据删除销毁
// 函数参数：队列指针
// 函数返回类型及内容：空
void queuepop(queue* pq);

// 函数名：queuefront
// 函数功能：取队头的一个数据
// 函数参数：队列指针
// 函数返回类型及内容：QUDataType，队头数据
QUDataType queuefront(queue* pq);

// 函数名：queueback
// 函数功能：取队尾的一个数据
// 函数参数：队列指针
// 函数返回类型及内容：QUDataType，队尾数据
QUDataType queueback(queue* pq);

// 函数名：queueempty
// 函数功能：判断队列是否为空
// 函数参数：队列指针
// 函数返回类型及内容：bool，真或假
bool queueempty(queue* pq);

// 函数名：queuesize
// 函数功能：给出队列内数据个数
// 函数参数：队列指针
// 函数返回类型及内容：int，队列内数据个数
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
	if (pq->head == NULL)//避免tail指向野指针
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