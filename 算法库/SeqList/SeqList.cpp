//*********************************
// 作者：suwu
// 环境: vs2019 win10
// 最后修改时间：2023/7/21 15:50
//*********************************
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListBoost(SeqList* ps)//扩容
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

void SeqListInit(SeqList* ps)//初始化
{
	if (ps == NULL)
	{
		perror("SeqListInit()");
	}
	ps->a = (SLDateType*)malloc(3*sizeof(SLDateType));
	ps->size = 0;
	ps->capacity = 3;
}

void SeqListDestroy(SeqList* ps)//空间释放
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

int SeqListFind(SeqList* ps, SLDateType x)//查找函数
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

void SeqListInsert(SeqList* ps, int pos, SLDateType x)//任意位置插入
{
	if (ps == NULL)
	{
		perror("SeqListInsert");
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
	ps->a[i] = x;//i下标位置处插入x（如果pos位置合理便是pos，不合理就是ps->size）
	ps->size++;//现有数据个数+1
}

void SeqListErase(SeqList* ps, int pos)//指定位置删除
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
	for (i = pos; i < ps->size; i++)//从前往后，挪位置，覆盖掉删除的数据
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPushBack(SeqList* ps, SLDateType x)//后插，笔试可用Insert函数实现。
{
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)//前插，笔试可用Insert函数实现。
{
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList* ps)//后删，笔试可用Erase函数实现。
{
	SeqListErase(ps, ps->size - 1);
}

void SeqListPopBack(SeqList* ps)//前删，笔试可用Erase函数实现。
{
	SeqListErase(ps, 0);
}