//*********************************
// 作者：suwu
// 环境: vs2019 win10
// 最后修改时间：2023/7/23 15:51
//*********************************
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListBoost(SeqList* ps)//扩容
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

void SeqListInit(SeqList* ps)//初始化
{
	if (ps == NULL)
	{
		perror("SeqListInit()");
	}
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestroy(SeqList* ps)//空间释放
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

void SeqListPrint(SeqList* ps)//遍历打印
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

int SeqListFind1(SeqList* ps, SLDateType x)//查找函数
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

void SeqListInsert(SeqList* ps, int pos, SLDateType x)//任意位置插入
{
	if (ps == NULL)
	{
		perror("SeqListInsert");
	}
	if (pos < 0 || pos > ps->size)//pos下标位置必须合理
	{
		return;
	}
	if (ps->size + 1 > ps->capacity)//空间不够就扩容
	{
		SeqListBoost(ps);
	}
	int i = 0;
	for (i = ps->size; i > pos; i--)//从后往前，挪位置，腾出空间插入
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;//pos下标位置处插入x
	ps->size++;//现有数据个数+1
}

void SeqListErase(SeqList* ps, int pos)//指定位置删除
{
	if (ps == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= ps->size)//pos位置必须合理
	{
		return;
	}
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)//从前往后，挪位置，覆盖掉删除的数据
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPushBack(SeqList* ps, SLDateType x)//尾插，笔试可用Insert函数实现。
{
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)//头插，笔试可用Insert函数实现。
{
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList* ps)//头删，笔试可用Erase函数实现。
{
	SeqListErase(ps, 0);
}

void SeqListPopBack(SeqList* ps)//尾删，笔试可用Erase函数实现。
{
	SeqListErase(ps, ps->size - 1);
}