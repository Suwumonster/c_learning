#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void my_strcat(char *des, char *sor)
{
	while (*des)
	{
		des++;
	}
	while (*sor)
	{
		*des = *sor;
		des++;
		sor++;
	}
	*des = '\0';
}
int main()
{
	char arr[20] = "abc";
	char brr[] = "2jsui";
	my_strcat(arr, brr);
	printf("%s\n", arr);
	return 0;
}