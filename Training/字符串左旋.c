#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#include <stdio.h>
char tmp[50] = { 0 };
void fun(char arr[], int k, int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < k; i++)
	{
		tmp[i] = arr[i];
	}
	for (i = 0; i < sz - k; i++)
	{
		arr[i] = arr[i + k];
	}
	for (i = sz - k, j = 0; j < k ; i++, j++)
	{
		arr[i] = tmp[j];
	}
}
int main()
{
	int k = 0;
	char arr[] = { "ABCD" };
	int sz = strlen(arr);
	scanf("%d", &k);
	fun(arr, k, sz);
	printf("%s\n", arr);
	return 0;
}