#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int DigitSum(int n )
{
	if (n < 9)
	{
		return n;
	}
	return n % 10 + DigitSum(n / 10);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", DigitSum(n));
	return 0;
}