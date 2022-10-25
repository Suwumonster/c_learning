#pragma once
#include <stdio.h>
#include <string.h>
#define Max 100

typedef struct STU
{
	char name[20];
	char sex[5];
	int age;
	char phonenumber[20];
	char address[20];
}stu;

typedef struct CONTACT
{
	stu data[Max];
	int sz;
	int Maxsize;
}contact;

void Init_con(contact* pc);

void add_con(contact* pc);

void print_con(contact* pc);

int search_con(contact* pc);

void print_stu(contact* pc, int i);

void del_con(contact* pc, int mark);

void revise_con(contact* pc, int mark);

void destroy_con(contact* pc);

void sort_con(contact* pc);