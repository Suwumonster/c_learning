#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int fun(int m, int n)
{
	if (n == 0)
	{
		return m;
	}
	return fun(n, m % n);
}
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &m, &n);
	printf("%d", fun(m, n));
	return 0;
}