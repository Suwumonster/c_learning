#define _CRT_SECURE_NO_WARNINGS 1
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
#include <stdio.h>
int left = 0;//空瓶
int fun(int n)
{
	left = n;
	while (left / 2)
	{
		n += left / 2;
		left = left % 2 + left / 2;
	}
	return n;
}
int main()
{
	int n = 0;//已经喝过的瓶数
	n = 20;
	printf("%d\n", fun(n));
	return 0;
}