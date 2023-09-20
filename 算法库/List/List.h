#pragma once
//
//*************************
// 作者：suwu
// 最后修改日期：2023/9/20 19:00
// 环境：win10 vs2019
// ************************
//
#include <stdio.h>
#include <assert.h>

//链表内数据存储类型
typedef int LTDateType;

// 双向带头循环链表 结构体
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDateType val;
}LTNode;

//初始化
// 函数名称：LTinit
// 函数功能：初始化LT，申请一个哨兵卫节点，把哨兵卫指针都指向自己
// 函数参数：无
// 返回类型及内容：返回一个哨兵卫节点
LTNode* LTinit();

//销毁
// 函数名称：LTDestory
// 函数功能：销毁LT，把包括哨兵卫节点在内所有节点都销毁
// 函数参数：传入哨兵卫节点
// 返回类型及内容：无
void LTDestory(LTNode* phead);

//申请节点
// 函数名称：LTBuyNode
// 函数功能：传入数据x，申请一个LT节点，并返回
// 函数参数：传入存储数据x
// 返回类型及内容：返回申请好的LT节点
LTNode* LTBuyNode(LTDateType x);

//打印节点
// 函数名称：LTPrint
// 函数功能：打印LT所有节点的数据
// 函数参数：哨兵卫节点
// 返回类型及内容：无
void LTPrint(LTNode* phead);

//尾插
// 函数名称：LTPushBack
// 函数功能：在LT链表尾部插入一个存储数据x的节点
// 函数参数：哨兵卫节点，数据x
// 返回类型及内容：无
void LTPushBack(LTNode* phead, LTDateType x);

//尾删
// 函数名称：LTTopBack
// 函数功能：删除LT链表尾部一个节点
// 函数参数：哨兵卫节点
// 返回类型及内容：无
void LTTopBack(LTNode* phead);

//头插
// 函数名称：LTPushFront
// 函数功能：在LT链表头部插入一个存储数据x的节点
// 函数参数：哨兵卫节点，数据x
// 返回类型及内容：无
void LTPushFront(LTNode* phead, LTDateType x);

//头删
// 函数名称：LTTopFront
// 函数功能：删除LT链表头部一个节点
// 函数参数：哨兵卫节点
// 返回类型及内容：无
void LTTopFront(LTNode* phead);

//查找节点
// 函数名称：LTFind
// 函数功能：查找数据与x相同的节点并返回地址
// 函数参数：哨兵卫节点，数据x
// 返回类型及内容：与数据x相同的节点地址
LTNode* LTFind(LTNode* phead, LTDateType x);


//在pos节点前面插入
// 函数名称：LTInsert
// 函数功能：在pos节点之前插入一个数据x的新节点
// 函数参数：pos节点，数据x
// 返回类型及内容：无
void LTInsert(LTNode* pos, LTDateType x);


//删除pos节点
// 函数名称：LTErase
// 函数功能：删除pos节点
// 函数参数：pos节点
// 返回类型及内容：无
void LTErase(LTNode* pos);