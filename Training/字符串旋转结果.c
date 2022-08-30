#define _CRT_SECURE_NO_WARNINGS 1
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
#include <stdio.h>
#include <string.h>

void lfun(char arr[], int k, int sz)//��������
{
	int i = 0;
	int j = 0;
	char tmp[50] = { 0 };
	for (i = 0; i < k; i++)//����
	{
		tmp[i] = arr[i];
	}
	for (i = 0; i < sz - k; i++)//�ƶ�
	{
		arr[i] = arr[i + k];
	}
	for (i = sz - k, j = 0; j < k; i++, j++)//��ת
	{
		arr[i] = tmp[j];
	}
}
void rfun(char arr[], int k, int sz)//��������
{
	int i = 0;
	int j = 0;
	char tmp[50] = { 0 };
	for (i = sz - k, j = 0; i < sz; i++, j++)//����
	{
		tmp[j] = arr[i];
	}
	for (i = sz - 1; i >= sz - k; i--)//�ƶ�
	{
		arr[i] = arr[i - k];
	}
	for (i = 0; i < k; i++)//��ת
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