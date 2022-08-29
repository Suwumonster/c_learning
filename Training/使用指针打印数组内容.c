#define _CRT_SECURE_NO_WARNINGS 1
//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//arr是一个整形一维数组。
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5 };
	int ptr = arr;
	int i = 0;
	for (i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		printf("%d ", *(arr + i));
	}
	return 0;
}