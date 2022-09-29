#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char* my_strncpy(char* des, const char* sor, size_t num)
{
	char* d = des;
	char* s = sor;
	while (*s && num--)
	{
		*d = *s;
		d++;
		s++;
	}
	while (*s == '\0' && num > 0 && *d)
	{
		*d = '\0';
		d++;
		num--;
	}
	return des;
}
int main()
{
	char sor[] = "hello";
	char des[40] = "asdfghjkl";
	my_strncpy(des, sor, 20);
	printf("%s\n", des);
	return 0;
}