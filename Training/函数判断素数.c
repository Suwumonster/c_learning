#define _CRT_SECURE_NO_WARNINGS 1
//ʵ��һ���������ж�һ�����ǲ���������
//��������ʵ�ֵĺ�����ӡ100��200֮���������
#include <stdio.h>
#include <math.h>
int fun(int n)//����������1�����Ƿ���0
{
	int i = 0;
	if (n == 1)//1��������
	{
		return 0;
	}
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n = 0;
	int i = 0;
	printf("����һ�������ж��Ƿ���������");
	scanf("%d", &n);
	printf("%d(1��ʾ�����������������0��ʾ��������)\n", fun(n));
	printf("100-200��������\n");
	for (i = 100; i <= 200; i++)
	{
		if (fun(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}