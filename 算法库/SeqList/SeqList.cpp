//*********************************
// ���ߣ�suwu
// ����: vs2019 win10
// ����޸�ʱ�䣺2023/7/21 15:50
//*********************************
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListBoost(SeqList* ps)//����
{
	SLDateType* arr = (SLDateType*)realloc(ps->a, 2 * ps->capacity* sizeof(SLDateType));
	if(arr != NULL)
	{
		ps->a = arr;
		ps->capacity *= 2;
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
	ps->a = (SLDateType*)malloc(3*sizeof(SLDateType));
	ps->size = 0;
	ps->capacity = 3;
}

void SeqListDestroy(SeqList* ps)//�ռ��ͷ�
{
	if (ps == NULL)
	{
		perror("SeqListDestroy()");
	}
	free(ps->a);
	ps->a = 0;
	ps->size = 0;
	ps->capacity = 0;
	free(ps);
	ps = 0;
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

int SeqListFind(SeqList* ps, SLDateType x)//���Һ���
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

void SeqListInsert(SeqList* ps, int pos, SLDateType x)//����λ�ò���
{
	if (ps == NULL)
	{
		perror("SeqListInsert");
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
	ps->a[i] = x;//i�±�λ�ô�����x�����posλ�ú������pos�����������ps->size��
	ps->size++;//�������ݸ���+1
}

void SeqListErase(SeqList* ps, int pos)//ָ��λ��ɾ��
{
	if (ps == NULL)
	{
		return;
	}
	if (pos >= ps->size)
	{
		return;
	}
	int i = 0;
	for (i = pos; i < ps->size; i++)//��ǰ����Ųλ�ã����ǵ�ɾ��������
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPushBack(SeqList* ps, SLDateType x)//��壬���Կ���Insert����ʵ�֡�
{
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)//ǰ�壬���Կ���Insert����ʵ�֡�
{
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList* ps)//��ɾ�����Կ���Erase����ʵ�֡�
{
	SeqListErase(ps, ps->size - 1);
}

void SeqListPopBack(SeqList* ps)//ǰɾ�����Կ���Erase����ʵ�֡�
{
	SeqListErase(ps, 0);
}