#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char c = 0;
    while (scanf("%c", &c) != EOF)
    {
        if (c >= 65 && c <= 90)
        {
            c = c + 32;
            printf("%c\n", c);
        }
        else
        {
            c = c - 32;
            printf("%c\n", c);
        }
        getchar();
    }
    return 0;
}