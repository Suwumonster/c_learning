#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[1001][1001] = { 0 };
int main()
{
	int n = 0;
	arr[1][1] = 1;
	printf("输入需要打印杨辉三角的行数:");
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}