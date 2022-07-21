#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int sum = 0;
	for (i = 1; i <= 100; i++)
	{
		int temp = i;
		int arr[3] = { 0 };
		arr[0] = temp % 10;
		arr[1] = temp / 10 % 10;
		arr[2] = temp / 100;
		for (int j = 0; j < 3; j++)
		{
			if (arr[j] == 9)
			{
				sum += 1;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}