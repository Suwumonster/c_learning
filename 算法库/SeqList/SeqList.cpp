//*********************************
// ���ߣ�suwu
// ����: vs2019 win10
// ����޸�ʱ�䣺2023/7/23 15:51
//*********************************
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListBoost(SeqList* ps)//����
{
	if (ps == NULL)
	{
		return;
	}
	int newcapacity = (ps->capacity == 0) ? 4 : 2 * ps->capacity;
	SLDateType* arr = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
	if(arr != NULL)
	{
		ps->a = arr;
		ps->capacity = newcapacity;
	}
	else
	{
		perror("SeqListBoost()");
	}
}

void SeqListInit(SeqList* ps)//��ʼ��
{
	if (ps == NULL)
	{
		perror("SeqListInit()");
	}
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestroy(SeqList* ps)//�ռ��ͷ�
{
	if (ps == NULL)
	{
		perror("SeqListDestroy()");
	}
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
	}
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)//������ӡ
{
	if (ps == NULL)
	{
		return;
	}
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

int SeqListFind1(SeqList* ps, SLDateType x)//���Һ���
{
	if (ps == NULL)
	{
		return -1;
	}
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

int SeqListFind2(SeqList* ps, SLDateType x, int begin)
{
	if (ps == NULL)
	{
		return -1;
	}
	for (int i = begin; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, int pos, SLDateType x)//����λ�ò���
{
	if (ps == NULL)
	{
		perror("SeqListInsert");
	}
	if (pos < 0 || pos > ps->size)//pos�±�λ�ñ������
	{
		return;
	}
	if (ps->size + 1 > ps->capacity)//�ռ䲻��������
	{
		SeqListBoost(ps);
	}
	int i = 0;
	for (i = ps->size; i > pos; i--)//�Ӻ���ǰ��Ųλ�ã��ڳ��ռ����
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;//pos�±�λ�ô�����x
	ps->size++;//�������ݸ���+1
}

void SeqListErase(SeqList* ps, int pos)//ָ��λ��ɾ��
{
	if (ps == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= ps->size)//posλ�ñ������
	{
		return;
	}
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)//��ǰ����Ųλ�ã����ǵ�ɾ��������
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPushBack(SeqList* ps, SLDateType x)//β�壬���Կ���Insert����ʵ�֡�
{
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)//ͷ�壬���Կ���Insert����ʵ�֡�
{
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList* ps)//ͷɾ�����Կ���Erase����ʵ�֡�
{
	SeqListErase(ps, 0);
}

void SeqListPopBack(SeqList* ps)//βɾ�����Կ���Erase����ʵ�֡�
{
	SeqListErase(ps, ps->size - 1);
}