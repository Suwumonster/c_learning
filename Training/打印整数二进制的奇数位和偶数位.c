#define _CRT_SECURE_NO_WARNINGS 1
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
#include <stdio.h>
int arr1[16] = { 0 };//����λ
int arr2[16] = { 0 };//ż��λ
void fun(int n)
{
	int i = 1;
	int j = 0;
	int k = 0;
	for (i = 1; i <= 32; i++)
	{
		if (i % 2 == 0)
		{
			arr2[k++] = n & 1;
		}
		else
		{
			arr1[j++] = n & 1;
		}
		n = n >> 1;
	}
}
void print(int arr[], int n)
{
	if (n <= 0)
	{
		return;
	}
	print(arr + 1, n - 1);
	printf(" %d", *arr);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	fun(n);
	print(arr2, 16);//ż��
	printf("\n");
	print(arr1, 16);//����
	return 0;
}