#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdbool.h>

// ******************************
// 作者：suwu
// 最后修改时间：2023/10/11 16:58
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


void stackinit(ST* ps)
{
	assert(ps);
	ps->a = (StDataType*)malloc(sizeof(StDataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->top = 0;
	ps->capacity = 4;
}
void stackdestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void stackpush(ST* ps, StDataType x)
{
	assert(ps);
	assert(ps->a);

	//扩容
	if (ps->top == ps->capacity)
	{
		StDataType* tmp = (StDataType*)realloc(ps->a, 2 * ps->capacity * sizeof(StDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void stackpop(ST* ps)
{
	assert(ps);
	assert(!stackempty(ps));
	ps->top--;
}

StDataType stacktop(ST* ps)
{
	assert(ps);
	assert(!stackempty(ps));
	return ps->a[ps->top - 1];
}

bool stackempty(ST* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return true;
	}
	return false;
}
int stacksize(ST* ps)
{
	assert(ps);
	return ps->top;
}


typedef struct {
	ST pushst;
	ST popst;
} MyQueue;

bool myQueueEmpty(MyQueue* obj);
int myQueuePeek(MyQueue* obj);

MyQueue* myQueueCreate() {
	MyQueue* qu = (MyQueue*)malloc(sizeof(MyQueue));
	stackinit(&qu->pushst);
	stackinit(&qu->popst);
	return qu;
}

void myQueuePush(MyQueue* obj, int x) {
	assert(obj);
	stackpush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) {
	assert(obj);
	assert(!myQueueEmpty(obj));
	int ret = myQueuePeek(obj);
	stackpop(&obj->popst);
	return ret;
}

int myQueuePeek(MyQueue* obj) {
	assert(obj);
	assert(!myQueueEmpty(obj));
	if (stackempty(&obj->popst))
	{
		while (!stackempty(&obj->pushst))
		{
			stackpush(&obj->popst, stacktop(&obj->pushst));
			stackpop(&obj->pushst);
		}
	}
	return stacktop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
	assert(obj);
	return stackempty(&obj->pushst) && stackempty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	assert(obj);
	stackdestroy(&obj->pushst);
	stackdestroy(&obj->popst);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/