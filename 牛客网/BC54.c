#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int year = 0;
    int months = 0;
    int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    while (scanf("%d %d", &year, &months) != EOF)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if (months != 2)
            {
                printf("%d\n", arr[months - 1]);
            }
            else
            {
                printf("29\n");
            }
        }
        else
        {
            printf("%d\n", arr[months - 1]);
        }
    }
    return 0;
}