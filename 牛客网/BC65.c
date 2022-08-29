#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void fun(double n)
{
    int i = 1;
    int j = 1;
    for (i = 1; i <= 2 * n + 1; i++)
    {
        for (j = 1; j <= 2 * n + 1; j++)
        {
            if (i < n + 1)
            {
                while ((j < (n + 1) * 2.0 - i) && (j > (n + 1 - i)*2 ))
                {
                    printf("*");
                    j++;
                }
                if ((j + i) / 2.0 == n + 1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            if (i >= n + 1)
            {
                while ((j < i) && (j > (i - n - 1) * 2))
                {
                    printf("*");
                    j++;
                }
                if (i == j)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
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