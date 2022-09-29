#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char* my_strstr(const char* str1, const char* str2)
{
	int i = 0;
	char* p1, * p2;
	if (!*str2)
	{
		return (char *)str1;
	}
	for (i = 0; *(str1 + i); i++)
	{
		p1 = str1 + i;
		p2 = str2;
		while ((*p1) && (*p2) && (*p1 == *p2))
		{
			p1++;
			p2++;
		}
		if (!*p2)
		{
			return (char*)(str1 + i);
		}
	}
	return 0;
}
int main()
{
	char str1[] = "abcdcdcdavd";
	char str2[] = "bcdc";
	printf("%s\n", my_strstr(str1, str2));
	return 0;
}