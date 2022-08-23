#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char a = 0;
    while (scanf("%c", &a) != EOF)
    {
        if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
        {
            printf("%c is an alphabet.\n", a);
        }
        else
        {
            printf("%c is not an alphabet.\n", a);
        }
        getchar();
    }
    return 0;
}