#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void my_strcpy(char* des, const char* sor)
{
	while (*sor)
	{
		*des = *sor;
		sor++;
		des++;
	}
	*des = '\0';
}
int main()
{
	char arr[] = "hello";
	char arr1[10] = { 0 };
	my_strcpy(arr1, arr);
	printf("%s\n", arr1);
	return 0;
}