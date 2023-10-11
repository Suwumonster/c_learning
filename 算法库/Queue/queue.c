#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

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
	if (pq->head == NULL)//±ÜÃâtailÖ¸ÏòÒ°Ö¸Õë
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