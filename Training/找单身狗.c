#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�

int ret[10] = { 0 };//��Ӧ�±�Ϊ1����ʾ���ǵ�����Ϊ0�ǵ���
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
	printf("������");
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