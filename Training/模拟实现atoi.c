#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int my_atoi(const char* str)
{
	int num = 0;
	int flag = 0;
	while (*str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			flag = 1;
		}
		str++;
	}
	while (*str)
	{
		while (*str == ' ')
		{
			str++;
		}
		if (*str >= '0' && *str <= '9')
		{
			num = num * 10 + *str - '0';
		}
		else
		{
			break;
		}
		str++;
	}
	if (flag == 1)
	{
		num = 0 - num;
	}
	return num;
}
int main()
{
	char str1[] = "hello";
	char str2[] = "  -9  999";
	int num1 = my_atoi(str1);
	int num2 = my_atoi(str2);
	printf("%d %d\n", num1, num2);
	return 0;
}