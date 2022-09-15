#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= (n - i); j++)
            {
                printf(" ");
            }
            printf("*\n");
        }
    }

    return 0;
}