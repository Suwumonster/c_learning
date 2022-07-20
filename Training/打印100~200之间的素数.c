#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 100;
	for (i = 100; i <= 200; i++)
	{
		int isprime = 1;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				isprime = 0;
				break;
			}
		}
		if (isprime == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}