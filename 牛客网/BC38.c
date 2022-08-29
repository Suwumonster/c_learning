#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int fun(int n, int num)
{
    if (num <= 0)
    {
        return 0;
    }
    int a = n / (int)pow(10, num);
    int b = n % (int)pow(10, num);
    return a * b + fun(n, num - 1);
}
int main()
{
    int i = 10000;
    for (i = 10000; i <= 99999; i++)
    {
        if (i == fun(i, 4))
        {
            printf("%d ", i);
        }
    }
    return 0;
}