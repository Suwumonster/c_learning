#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void bubble(int arr[], int num)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (arr[j] > arr[i])
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
	int arr[5] = { 5,8,2,8,3 };
	int num = sizeof(arr) / 4;
	bubble(arr, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}