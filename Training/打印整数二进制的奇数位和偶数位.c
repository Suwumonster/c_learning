#define _CRT_SECURE_NO_WARNINGS 1
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
#include <stdio.h>
int arr1[16] = { 0 };//奇数位
int arr2[16] = { 0 };//偶数位
void fun(int n)
{
	int i = 1;
	int j = 0;
	int k = 0;
	for (i = 1; i <= 32; i++)
	{
		if (i % 2 == 0)
		{
			arr2[k++] = n & 1;
		}
		else
		{
			arr1[j++] = n & 1;
		}
		n = n >> 1;
	}
}
void print(int arr[], int n)
{
	if (n <= 0)
	{
		return;
	}
	print(arr + 1, n - 1);
	printf(" %d", *arr);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	fun(n);
	print(arr2, 16);//偶数
	printf("\n");
	print(arr1, 16);//奇数
	return 0;
}