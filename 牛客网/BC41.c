#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int num = 0;
    while (scanf("%d", &num) != EOF)
    {
        if (num >= 140)
        {
            printf("Genius");
        }
    }
    return 0;
}