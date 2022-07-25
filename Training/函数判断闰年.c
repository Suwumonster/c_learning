#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void fun(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("%d是闰年！\n", year);
	}
	else
	{
		printf("%d不是闰年！\n", year);
	}
}
int main()
{
	int year = 0;
	printf("输入一个年份，判断是否是闰年：");
	scanf("%d", &year);
	fun(year);
	return 0;
}