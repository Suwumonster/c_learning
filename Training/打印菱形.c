#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 6 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("*");
		for (j = 0; j < i; j++)
		{
			printf("*");
		}
		for (j = 0; j < 6 - i; j++)
		{
			printf(" ");
		}
		printf("\n");
	}
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 5 - i; j++)
		{
			printf("*");
		}
		printf("*");
		for (j = 0; j < 5 - i; j++)
		{
			printf("*");
		}
		for (j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		printf("\n");
	}
}