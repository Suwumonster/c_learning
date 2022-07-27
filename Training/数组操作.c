#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//����һ���������飬��ɶ�����Ĳ���
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�
//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
void init(int arr[], int num)
{
	memset(arr, 0, num*4);
}
void print(int arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void reverse(int arr[], int num)
{
	for (int i = 0; i < num / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[num - 1 - i];
		arr[num - 1 - i] = temp;
	}
}
int main()
{
	int arr[10];
	int num = sizeof(arr) / 4;
	init(arr, num);
	print(arr, num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	reverse(arr, num);
	print(arr, num);
	return 0;
}
