#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int fun(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fun(n - 2) + fun(n - 1);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", fun(n));
	return 0;
}