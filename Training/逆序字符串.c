#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int left = 0;//�����ַ����±�֮һ
int right = 0;//�����ַ����±�֮һ
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
	for (i = 0; str[i] != '\0'; i++)//���forѭ����i�����ַ����ĳ���
	{
	}
	left = 0;//��һ���ַ����±�
	right = i - 1;//���һ���ַ����±�
	reverse_string(str);
	printf("%s", str);
	return 0;
}