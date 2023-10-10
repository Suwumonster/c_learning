#pragma once
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>
// ******************************
// 作者：suwu
// 最后修改时间：2023/10/10 15:23
// ******************************
//自定义存储数据类型
typedef int StDataType;

//栈的结构体
typedef struct STACK
{
	StDataType* a;
	int top;
	int capacity;
}ST;

// 函数名：stackinit
// 函数功能：初始化栈，为栈申请空间
// 函数参数：栈的指针
// 函数返回类型及内容：空
void stackinit(ST* ps);

// 函数名：stackdestroy
// 函数功能：销毁栈，为栈释放空间
// 函数参数：栈的指针
// 函数返回类型及内容：空
void stackdestroy(ST* ps);

// 函数名：stackpush
// 函数功能：压栈，把x压入栈顶
// 函数参数：栈的指针，数据x
// 函数返回类型及内容：空
void stackpush(ST* ps, StDataType x);

// 函数名：stackpop
// 函数功能：弹栈，删除栈顶元素
// 函数参数：栈的指针
// 函数返回类型及内容：空
void stackpop(ST* ps);

// 函数名：stacktop
// 函数功能：出栈，返回栈顶位置的数据
// 函数参数：栈的指针
// 函数返回类型及内容：栈储存数据的类型，栈顶位置的数据
StDataType stacktop(ST* ps);

// 函数名：stackempty
// 函数功能：判断栈是否为空，为空返回真，否则返回假
// 函数参数：栈的指针
// 函数返回类型及内容：bool，真或假
bool stackempty(ST* ps);

// 函数名：stacksize
// 函数功能：返回栈中数据个数
// 函数参数：栈的指针
// 函数返回类型及内容：int，栈中数据个数
int stacksize(ST* ps);

