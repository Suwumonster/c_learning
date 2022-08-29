#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int fun(char arr[])
{
	int i = 0;
	for (i = 0; arr[i] != '\0'; i++)
	{}
	return i;
}
int main()
{
	char arr[10] = { "hello" };
	printf("%d\n", fun(arr));
	return 0;
}