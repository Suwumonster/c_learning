#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
float my_pow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	if (k > 0)
	{
		return n * my_pow(n, k - 1);
	}
	if (k < 0)
	{
		return 1.0 / my_pow(n, -k);
	}
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	printf("%f\n", my_pow(n, k));
	return 0;
}
