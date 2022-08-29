#define _CRT_SECURE_NO_WARNINGS 1
//调整数组使奇数全部都位于偶数前面。
#include <stdio.h>
void fun(int arr[], int num)
{
	int left = 0;
	int right = num - 1;
	while (left < right)
	{
		while (arr[left] % 2 == 1 && left < right)
		{
			left++;
		}
		while (arr[right] % 2 == 0 && left < right)
		{
			right--;
		}
		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	fun(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}