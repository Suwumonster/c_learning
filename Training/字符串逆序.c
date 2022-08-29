#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char arr[10001] = { 0 };
int main()
{
	int i = 0;
	char ch = 'c';
	int left = 0;
	int right = 0;
	do
	{
		ch = getchar();
		arr[i++] = ch;
	} while (ch != '\n');
	arr[i - 1] = '\0';
	right = i - 2;
	while (left < right)
	{
		char temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
	printf("%s", arr);
	return 0;
}