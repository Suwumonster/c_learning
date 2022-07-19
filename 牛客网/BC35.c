#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    char ch = 0;
    scanf("%c", &ch);
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 154))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}