#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

void* my_memcpy(void * des, const void* sor, size_t count)
{
	void* ret = des;
	assert(des);
	assert(sor);
	while (count--)
	{
		*(char*)des = *(char*)sor;
		des = (char*)des + 1;
		sor = (char*)sor + 1;
	}
	return ret;
}
int main()
{
	char arr[] = "abcdef";
	char brr[] = "fghjkl";
	my_memcpy(arr, brr, 4);
	printf("%s\n", arr);
	return 0;
}