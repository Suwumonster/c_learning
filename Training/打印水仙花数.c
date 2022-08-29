#define _CRT_SECURE_NO_WARNINGS 1
//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。
#include <stdio.h>
#include <math.h>
int fun(int n, int num)
{
	if (n < 10)
	{
		return pow(n, num);
	}
	return pow(n % 10,num) + fun(n / 10,num);
}
int func(int n)
{
	int i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return i;
}
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		if (i == fun(i,func(i)) || i == 0)
		{
			printf("%d ", i);
		}
	}
	return 0;
}