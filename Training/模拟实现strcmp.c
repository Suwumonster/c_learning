#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int my_strcmp(const char* a, const char* b)
{
	while (*a != '\0' && *b != '\0')
	{
		if (*a > *b)
		{
			return -1;
		}
		else if (*a < *b)
		{
			return 1;
		}
		a++;
		b++;
	}
	if (*a == '\0' && *b == '\0')
	{
		return 0;
	}
	else if (*a == '\0')
	{
		return 1;
	}
	else if (*b == '\0')
	{
		return -1;
	}
}
int main()
{
	char arr[] = "abf";
	char brr[] = "abc";
	printf("%d\n", my_strcmp(arr, brr));
	return 0;
}