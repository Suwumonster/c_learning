//*********************************
// 作者：suwu
// 环境: vs2019 win10
// 最后修改时间：2023/7/23 15:51
//*********************************
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;//顺序表里一个存储单元的数据类型，如需修改，只需在此把int修改为其他数据类型

// 自定义顺序表的数据结构
typedef struct SeqList
{
	SLDateType* a;//顺序表数据
	int size;//现有存储数据个数
	int capacity;//顺序表容量
}SeqList;

// 对数据的管理:增删查改 

// 函数名称：SeqListInit
// 函数功能：初始化顺序表，为顺序表申请空间，顺序表容量初始化为3个。
// 函数参数：顺序表指针ps
// 返回类型及内容：空
void SeqListInit(SeqList* ps);//初始化

// 函数名称：SeqListDestroy
// 函数功能：销毁顺序表，释放顺序表申请过的空间，并把指针置空。
// 函数参数：顺序表指针ps
// 返回类型及内容：空
void SeqListDestroy(SeqList* ps);//销毁

// 函数名称：SeqListPrint
// 函数功能：按顺序表里数据排放顺序打印数据。
// 函数参数：顺序表指针ps
// 返回类型及内容：空
void SeqListPrint(SeqList* ps);//打印

// 顺序表查找
// 函数名称：SeqListFind
// 函数功能：查找顺序表里面的数据，和x相同的第一个数据的下标将被返回。
// 函数参数：顺序表指针ps，比对数据x
// 返回类型及内容：和x相同的第一个数据的下标，如果没找到或者顺序表指针ps为空则返回-1
int SeqListFind1(SeqList* ps, SLDateType x);

// 函数名称：SeqListFind
// 函数功能：从begin下标位置开始查找顺序表里面的数据，和x相同的第一个数据的下标将被返回。
//			 配合while循环可以把所有与x值相同的数据删除
// 函数参数：顺序表指针ps，比对数据x，开始查找下标begin
// 返回类型及内容：和x相同的第一个数据的下标，如果没找到或者顺序表指针ps为空则返回-1
int SeqListFind2(SeqList* ps, SLDateType x, int begin);

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos);




void SeqListPushBack(SeqList* ps, SLDateType x);//尾插，笔试可用Insert函数实现。
void SeqListPushFront(SeqList* ps, SLDateType x);//头插，笔试可用Insert函数实现。
void SeqListPopFront(SeqList* ps);//头删，笔试可用Erase函数实现。
void SeqListPopBack(SeqList* ps);//尾删，笔试可用Erase函数实现。