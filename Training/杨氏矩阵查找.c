#define _CRT_SECURE_NO_WARNINGS 1
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
#include <stdio.h>
int arr[50][50] = { 0 };
int ii = 0;
int jj = 0;
int fun(int row, int col, int num)
{
	//从右上角开始检验
	for (ii = 0; ii < row; ii++)
	{
		for (jj = col - 1; jj >= 0; jj--)
		{
			if (num > arr[ii][jj])//如果目标数大于右上角的数，抛弃这一行。
			{
				break;
			}
			else if (num == arr[ii][jj])
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int row = 0;
	int col = 0;
	int i = 0;
	int j = 0;
	int num = 0;
	printf("请输入杨氏矩阵的行数和列数\n");
	scanf("%d %d", &row, &col);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d", &num);
	if (fun(row, col, num))
	{
		printf("找到了！下标为%d,%d\n", ii, jj);
	}
	else
	{
		printf("没找到！\n");
	}
}