#define _CRT_SECURE_NO_WARNINGS 1
//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ��������� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������
#include <stdio.h>
#include <math.h>
int fun(int n, int num)
{
	if (n < 10)
	{
		return pow(n, num);
	}
	return pow(n % 10,num) + fun(n / 10,num);
}
int func(int n)
{
	int i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return i;
}
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		if (i == fun(i,func(i)) || i == 0)
		{
			printf("%d ", i);
		}
	}
	return 0;
}