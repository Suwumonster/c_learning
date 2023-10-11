#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

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