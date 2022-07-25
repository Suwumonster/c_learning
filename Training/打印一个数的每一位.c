#define _CRT_SECURE_NO_WARNINGS 1
//递归方式实现打印一个整数的每一位
#include <stdio.h>
void fun(int n)
{
	if (n < 9)
	{
		printf("%d", n);
		return;
	}
	fun(n / 10);
	printf(" %d", n % 10);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	fun(n);
	return 0;
}