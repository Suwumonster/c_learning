#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int n = 0;
    int i = 0;
    int j = 0;
    while (~scanf("%d", &n)) 
    {
        for (i = 1; i <= n; i++) 
        {
            for (j = 1; j <= n; j++) 
            {
                if (i + j > n) 
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