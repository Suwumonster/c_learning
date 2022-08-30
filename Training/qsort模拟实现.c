#define _CRT_SECURE_NO_WARNINGS 1
//模仿qsort的功能实现一个通用的冒泡排序
#include <stdio.h>

int_cmp(const void* a, const void* b)
{
	return (*(int *)a - *(int *)b);
}

void swap(const void* a, const void* b, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char temp = *((char *) a + i);
		*((char*)a + i) = *((char*)b + i);
		*((char*)b + i) = temp;
	}
}

void bubble(void* base, int count, int size, int(*cmp)(const void* a, const void* b))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char*)base + j*size, (char *)base + (j + 1)*size) > 0)
			{
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 3, 7, 3, 4, 6, 8, 10 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sz, sizeof(int), int_cmp);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}