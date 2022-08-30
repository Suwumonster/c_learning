#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int int_cmp(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int arr[] = { 1, 2, 5, 3, 1,4, 57, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	qsort(arr, sz, sizeof(int), int_cmp);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}