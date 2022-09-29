#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char* my_strncat(char* des, char* sor, size_t num)
{
	char* d = des;
	char* s = sor;
	while (*d)
	{
		d++;
	}
	while (*s && num--)
	{
		*d = *s;
		d++;
		s++;
	}
	while (*s == '\0' && num > 0)
	{
		*d = '\0';
		d++;
	}
	return des;
}
int main()
{
	char str1[20] = "To be ";
	char str2[20] = "or not to be";
	my_strncat(str1, str2, 6);
	printf("%s\n", str1);
	return 0;
}