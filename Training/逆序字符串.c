#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int left = 0;//交换字符的下标之一
int right = 0;//交换字符的下标之一
void reverse_string(char* string)
{
	if (left >= right)
	{
		return;
	}
	char temp = string[left];
	string[left] = string[right];
	string[right] = temp;
	left++;
	right--;
	reverse_string(string);
}
int main()
{
	int i = 0;
	char str[20] = { 0 };
	scanf("%s", str);
	for (i = 0; str[i] != '\0'; i++)//这个for循环后i就是字符串的长度
	{
	}
	left = 0;//第一个字符的下标
	right = i - 1;//最后一个字符的下标
	reverse_string(str);
	printf("%s", str);
	return 0;
}