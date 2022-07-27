#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 1;
	int b = 1;
	int n = 0;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
	{
		int temp = b;
		b = a + b;
		a = temp;
	}
	printf("%d", b);
	return 0;
}