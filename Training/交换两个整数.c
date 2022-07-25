#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void fun(int* px, int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}
int main()
{
	int y = 0;
	int x = 0;
	int* px = &x;
	int* py = &y;
	scanf("%d %d", &x, &y);
	printf("x = %d,y = %d\n", x, y);
	fun(px, py);
	printf("x = %d,y = %d\n", x, y);
	return 0;
}