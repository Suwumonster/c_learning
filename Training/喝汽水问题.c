#define _CRT_SECURE_NO_WARNINGS 1
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
#include <stdio.h>
int left = 0;//��ƿ
int fun(int n)
{
	left = n;
	while (left / 2)
	{
		n += left / 2;
		left = left % 2 + left / 2;
	}
	return n;
}
int main()
{
	int n = 0;//�Ѿ��ȹ���ƿ��
	n = 20;
	printf("%d\n", fun(n));
	return 0;
}