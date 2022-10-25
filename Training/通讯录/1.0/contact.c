#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void Init_con(contact* pc)
{
	pc->sz = 0;
	pc->Maxsize = Max;
}

void add_con(contact* pc)
{
	if (pc->sz >= pc->Maxsize)
	{
		printf("空间不足添加失败\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex); 
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话号码：");
	scanf("%s", pc->data[pc->sz].phonenumber);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].address);
	(pc->sz)++;
	printf("添加成功!\n");
}


void print_con(contact* pc)
{
	int i = 0;
	printf("%5d\t", 0);
	printf("%20s\t", "姓名");
	printf("%5s\t", "性别");
	printf("%5s\t", "年龄");
	printf("%20s\t", "电话");
	printf("%20s\n", "住址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%5d\t", i + 1);
		printf("%20s\t", pc->data[i].name);
		printf("%5s\t", pc->data[i].sex);
		printf("%5d\t", pc->data[i].age);
		printf("%20s\t", pc->data[i].phonenumber);
		printf("%20s\n", pc->data[i].address);
	}
}

int search_con(contact* pc)
{
	char name[20] = { 0 };
	int i = 0;
	printf("请输入姓名:>");
	scanf("%s", name);
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void del_con(contact* pc, int mark)
{
	if (mark == -1)
	{
		printf("删除失败\n");
		return;
	}
	int i = mark;
	for (i = mark;( i < pc->sz )&&( i < (pc->Maxsize - 1)); i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	(pc->sz)--;
	printf("删除成功!\n");
}

void print_stu(contact* pc, int i)
{
	if (i == -1)
	{
		printf("没找到\n");
		return;
	}
	printf("找到了,该学生信息如下:\n");
	printf("%20s\t", "姓名");
	printf("%5s\t", "性别");
	printf("%5s\t", "年龄");
	printf("%20s\t", "电话");
	printf("%20s\n", "住址");
	printf("%20s\t", pc->data[i].name);
	printf("%5s\t", pc->data[i].sex);
	printf("%5d\t", pc->data[i].age);
	printf("%20s\t", pc->data[i].phonenumber);
	printf("%20s\n", pc->data[i].address);
}

void revise_con(contact* pc, int mark)
{
	if (mark == -1)
	{
		printf("修改失败！无此人\n");
		return;
	}
	print_stu(pc, mark);
	printf("请输入姓名：");
	scanf("%s", pc->data[mark].name);
	printf("请输入性别：");
	scanf("%s", pc->data[mark].sex);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[mark].age));
	printf("请输入电话号码：");
	scanf("%s", pc->data[mark].phonenumber);
	printf("请输入地址：");
	scanf("%s", pc->data[mark].address);
	printf("修改成功\n");
}

void destroy_con(contact* pc)
{
	pc->sz = 0;
}

void sort_con(contact* pc)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < pc->sz - 1; i++)
	{
		for (j = i + 1; j < pc->sz; j++)
		{
			if (strcmp(pc->data[i].name, pc->data[j].name) > 0)
			{
				stu tmp = pc->data[i];
				pc->data[i] = pc->data[j];
				pc->data[j] = tmp;
			}
		}
	}
	printf("排序成功\n");
}