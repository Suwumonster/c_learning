#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数，判断一个数是不是素数。
//利用上面实现的函数打印100到200之间的素数。
#include <stdio.h>
#include <math.h>
int fun(int n)//是素数返回1，不是返回0
{
	int i = 0;
	if (n == 1)//1不是素数
	{
		return 0;
	}
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n = 0;
	int i = 0;
	printf("输入一个数，判断是否是素数：");
	scanf("%d", &n);
	printf("%d(1表示你输入的数是素数，0表示不是素数)\n", fun(n));
	printf("100-200的素数：\n");
	for (i = 100; i <= 200; i++)
	{
		if (fun(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}