#define _CRT_SECURE_NO_WARNINGS 1
//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
//arr��һ������һά���顣
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5 };
	int ptr = arr;
	int i = 0;
	for (i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		printf("%d ", *(arr + i));
	}
	return 0;
}