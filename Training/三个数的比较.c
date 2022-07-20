#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void sort(int arr[])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main()
{
	int i = 0;
	int arr[3] = { 0 };
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr);
	for (i = 0; i < 3; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}