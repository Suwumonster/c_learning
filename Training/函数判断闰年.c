#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void fun(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("%d�����꣡\n", year);
	}
	else
	{
		printf("%d�������꣡\n", year);
	}
}
int main()
{
	int year = 0;
	printf("����һ����ݣ��ж��Ƿ������꣺");
	scanf("%d", &year);
	fun(year);
	return 0;
}