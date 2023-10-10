#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdbool.h>
//�Զ���洢��������
typedef char StDataType;

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

bool isValid(char* s) {
	ST st;
	stackinit(&st);
	//ɨ�赽��������ջ �����ų�ջ
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
		{
			stackpush(&st, *s);
		}
		else
		{
			if (stackempty(&st))
			{
				stackdestroy(&st);
				return false;
			}
			char tmp = stacktop(&st);
			stackpop(&st);
			if ((*s == ')' && tmp != '(') ||
				(*s == ']' && tmp != '[') ||
				(*s == '}' && tmp != '{'))
			{
				stackdestroy(&st);
				return false;
			}
		}
		s++;
	}
	if (!stackempty(&st))
	{
		stackdestroy(&st);
		return false;
	}
	stackdestroy(&st);
	return true;
}