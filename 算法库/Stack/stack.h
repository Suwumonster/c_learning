#pragma once
#include <stdbool.h>
#include <assert.h>
#include <malloc.h>
// ******************************
// ���ߣ�suwu
// ����޸�ʱ�䣺2023/10/10 15:23
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

