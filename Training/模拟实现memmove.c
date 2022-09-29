#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void* my_memmove(void* des, void* sor, size_t count)
{
	void* ret = des;
	if ((char *)sor - (char *)des >= 0)
	{
		while (count--)
		{
			*(char*)des = *(char*)sor;
			des = (char*)des + 1;
			sor = (char*)sor + 1;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)des + count) = *((char*)sor + count);
		}
	}
	return ret;
}
int main()
{
	char arr[] = "abcdf";
	my_memmove(arr + 2, arr, 2);
	printf("%s\n", arr);
	return 0;
}