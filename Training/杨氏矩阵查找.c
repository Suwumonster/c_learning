#define _CRT_SECURE_NO_WARNINGS 1
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
#include <stdio.h>
int arr[50][50] = { 0 };
int ii = 0;
int jj = 0;
int fun(int row, int col, int num)
{
	//�����Ͻǿ�ʼ����
	for (ii = 0; ii < row; ii++)
	{
		for (jj = col - 1; jj >= 0; jj--)
		{
			if (num > arr[ii][jj])//���Ŀ�����������Ͻǵ�����������һ�С�
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
	printf("���������Ͼ��������������\n");
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
		printf("�ҵ��ˣ��±�Ϊ%d,%d\n", ii, jj);
	}
	else
	{
		printf("û�ҵ���\n");
	}
}