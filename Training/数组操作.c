#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
void init(int arr[], int num)
{
	memset(arr, 0, num*4);
}
void print(int arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void reverse(int arr[], int num)
{
	for (int i = 0; i < num / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[num - 1 - i];
		arr[num - 1 - i] = temp;
	}
}
int main()
{
	int arr[10];
	int num = sizeof(arr) / 4;
	init(arr, num);
	print(arr, num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	reverse(arr, num);
	print(arr, num);
	return 0;
}
