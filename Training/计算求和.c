#define _CRT_SECURE_NO_WARNINGS 1
//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
#include <stdio.h>
int a = 2;
int fun(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		num = num * 10 + a;
	}
	return num + fun(n - 1);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", fun(n));
	return 0;
}