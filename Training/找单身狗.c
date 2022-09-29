#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。

int ret[10] = { 0 };//对应下标为1，表示不是单身狗，为0是单身狗
int main()
{
	int arr[10] = { 55, 3, 1, 1, 3, 2, 3, 2, 2, 2};
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		if (ret[i] == 1)
		{
			continue;
		}
		for (j = i + 1; j < 10; j++)
		{
			if (ret[j] == 1)
			{
				continue;
			}
			if (arr[i] == arr[j])
			{
				ret[i] = 1;
				ret[j] = 1;
				break;
			}
		}
	}
	printf("单身狗：");
	for (i = 0; i < 10; i++)
	{
		if (ret[i] == 0)
		{
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
	return 0;
}