#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int temp = 0;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &temp);
        sum += temp;
    }
    printf("%.1f", sum / 5.0);
    return 0;
}