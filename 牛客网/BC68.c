#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void fun(double n)
{
    int i = 1;
    int j = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j == i || ((j + i) / 2.0 == (1 + n) / 2.0))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        fun(n);
    }
    return 0;
}