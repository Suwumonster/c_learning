#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdbool.h>

// ******************************
// ���ߣ�suwu
// ����޸�ʱ�䣺2023/10/11 16:58
// ******************************
//�Զ���洢��������
typedef int StDataType;

//ջ�Ľṹ��
typedef struct STACK
{
	StDataType* a;
	int top;
	int capacity;
}ST;

// ��������stackinit
// �������ܣ���ʼ��ջ��Ϊջ����ռ�
// ����������ջ��ָ��
// �����������ͼ����ݣ���
void stackinit(ST* ps);

// ��������stackdestroy
// �������ܣ�����ջ��Ϊջ�ͷſռ�
// ����������ջ��ָ��
// �����������ͼ����ݣ���
void stackdestroy(ST* ps);

// ��������stackpush
// �������ܣ�ѹջ����xѹ��ջ��
// ����������ջ��ָ�룬����x
// �����������ͼ����ݣ���
void stackpush(ST* ps, StDataType x);

// ��������stackpop
// �������ܣ���ջ��ɾ��ջ��Ԫ��
// ����������ջ��ָ��
// �����������ͼ����ݣ���
void stackpop(ST* ps);

// ��������stacktop
// �������ܣ���ջ������ջ��λ�õ�����
// ����������ջ��ָ��
// �����������ͼ����ݣ�ջ�������ݵ����ͣ�ջ��λ�õ�����
StDataType stacktop(ST* ps);

// ��������stackempty
// �������ܣ��ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ����棬���򷵻ؼ�
// ����������ջ��ָ��
// �����������ͼ����ݣ�bool������
bool stackempty(ST* ps);

// ��������stacksize
// �������ܣ�����ջ�����ݸ���
// ����������ջ��ָ��
// �����������ͼ����ݣ�int��ջ�����ݸ���
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

	//����
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