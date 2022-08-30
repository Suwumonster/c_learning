#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int n = 0;
    int i = 0;
    int j = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}