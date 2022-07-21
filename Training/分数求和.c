#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 1;
	float sum = 0.0;
	for (i = 1; i <= 100; i++)
	{
		sum += (pow(-1.0, i - 1) / i);
	}
	printf("%f\n", sum);
	return 0;
}