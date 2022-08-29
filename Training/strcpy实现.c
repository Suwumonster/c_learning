#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char arr[1000] = { 0 };
void fun(char arr1[], char arr2[])
{
	int i = 0;
	for (i = 0; arr2[i] != '\0'; i++)
	{
		arr1[i] = arr2[i];
	}
	arr1[i] = '\0';
}
int main()
{
	char ar[10] = { 0 };
	scanf("%s", ar);
	fun(arr, ar);
	printf("%s\n", arr);
	return 0;
}