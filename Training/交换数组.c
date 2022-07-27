#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 5,4,3,2,1 };
	for (int i = 0; i < 5; i++)
	{
		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}