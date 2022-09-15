#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int a_num = 0;
    int b_num = 0;
    char ch = 0;
    while ((scanf("%c", &ch) && ch != '0'))
    {
        if (ch == 'A')
        {
            a_num++;
        }
        else
        {
            b_num++;
        }
    }
    if (a_num > b_num)
    {
        printf("A\n");
    }
    else if (a_num < b_num)
    {
        printf("B\n");
    }
    else
    {
        printf("E\n");
    }
    return 0;
}