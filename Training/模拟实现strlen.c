#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
size_t my_strlen(const char* str)
{
	char* p = 0;
	p = str;
	while (*p != '\0')
	{
		p++;
	}
	return p - str;
}
int main()
{
	char arr[] = "hello world";
	printf("%d\n", my_strlen(arr));
	return 0;
}