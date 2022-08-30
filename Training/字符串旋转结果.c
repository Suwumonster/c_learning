#define _CRT_SECURE_NO_WARNINGS 1
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
#include <stdio.h>
#include <string.h>

void lfun(char arr[], int k, int sz)//左旋函数
{
	int i = 0;
	int j = 0;
	char tmp[50] = { 0 };
	for (i = 0; i < k; i++)//储存
	{
		tmp[i] = arr[i];
	}
	for (i = 0; i < sz - k; i++)//移动
	{
		arr[i] = arr[i + k];
	}
	for (i = sz - k, j = 0; j < k; i++, j++)//旋转
	{
		arr[i] = tmp[j];
	}
}
void rfun(char arr[], int k, int sz)//右旋函数
{
	int i = 0;
	int j = 0;
	char tmp[50] = { 0 };
	for (i = sz - k, j = 0; i < sz; i++, j++)//储存
	{
		tmp[j] = arr[i];
	}
	for (i = sz - 1; i >= sz - k; i--)//移动
	{
		arr[i] = arr[i - k];
	}
	for (i = 0; i < k; i++)//旋转
	{
		arr[i] = tmp[j];
	}
}

int fun(char arr1[], char arr2[], int sz)
{
	int i = 0;
	for (i = 1; i < sz; i++)
	{
		char tmp1[50] = { 0 };
		char tmp2[50] = { 0 };
		for (int j = 0; j < sz; j++)
		{
			tmp1[j] = arr1[j];
			tmp2[j] = arr1[j];
		}
		lfun(tmp1, i, sz);
		rfun(tmp2, i, sz);
		if (strcmp(tmp1, arr2) == 0 || strcmp(tmp2, arr2) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char arr1[50] = { 0 };
	char arr2[50] = { 0 };
	scanf("%s", arr1);
	scanf("%s", arr2);
	int sz = strlen(arr1);
	int ret = fun(arr1, arr2, sz);
	printf("%d\n", ret);
	return 0;
}