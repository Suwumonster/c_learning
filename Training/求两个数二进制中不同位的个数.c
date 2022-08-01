#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int fun(int n)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < 32; i++)
	{
		if (n & 1)
		{
			sum++;
		}
		n = n >> 1;
	}
	return sum;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d\n", fun(a ^ b));
	return 0;
}