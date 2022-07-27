#define _CRT_SECURE_NO_WARNINGS 1
//ตÝน้
#include <stdio.h>
int my_strlen(char arr[])
{
	if ((*arr) == '\0')
	{
		return 0;
	}
	return 1 + my_strlen(arr + 1);
}
int main()
{
	char arr[20] = { 0 };
	scanf("%s", arr);
	printf("%d\n", my_strlen(arr));
	return 0;
}