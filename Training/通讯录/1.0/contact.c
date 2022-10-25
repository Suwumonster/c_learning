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
		printf("�ռ䲻�����ʧ��\n");
		return;
	}
	printf("������������");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�");
	scanf("%s", pc->data[pc->sz].sex); 
	printf("���������䣺");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("������绰���룺");
	scanf("%s", pc->data[pc->sz].phonenumber);
	printf("�������ַ��");
	scanf("%s", pc->data[pc->sz].address);
	(pc->sz)++;
	printf("��ӳɹ�!\n");
}


void print_con(contact* pc)
{
	int i = 0;
	printf("%5d\t", 0);
	printf("%20s\t", "����");
	printf("%5s\t", "�Ա�");
	printf("%5s\t", "����");
	printf("%20s\t", "�绰");
	printf("%20s\n", "סַ");
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
	printf("����������:>");
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
		printf("ɾ��ʧ��\n");
		return;
	}
	int i = mark;
	for (i = mark;( i < pc->sz )&&( i < (pc->Maxsize - 1)); i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	(pc->sz)--;
	printf("ɾ���ɹ�!\n");
}

void print_stu(contact* pc, int i)
{
	if (i == -1)
	{
		printf("û�ҵ�\n");
		return;
	}
	printf("�ҵ���,��ѧ����Ϣ����:\n");
	printf("%20s\t", "����");
	printf("%5s\t", "�Ա�");
	printf("%5s\t", "����");
	printf("%20s\t", "�绰");
	printf("%20s\n", "סַ");
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
		printf("�޸�ʧ�ܣ��޴���\n");
		return;
	}
	print_stu(pc, mark);
	printf("������������");
	scanf("%s", pc->data[mark].name);
	printf("�������Ա�");
	scanf("%s", pc->data[mark].sex);
	printf("���������䣺");
	scanf("%d", &(pc->data[mark].age));
	printf("������绰���룺");
	scanf("%s", pc->data[mark].phonenumber);
	printf("�������ַ��");
	scanf("%s", pc->data[mark].address);
	printf("�޸ĳɹ�\n");
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
	printf("����ɹ�\n");
}