#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    double money = 0;
    int month = 0;
    int day = 0;
    int is_cheaper = 0;
    scanf("%lf %d %d %d", &money, &month, &day, &is_cheaper);
    if (month == 11 && day == 11)
    {
        if (is_cheaper == 1)
        {
            money = money * 0.7 - 50;
        }
        else
        {
            money = money * 0.7;
        }
    }
    else if (month == 12 && day == 12)
    {
        if (is_cheaper == 1)
        {
            money = money * 0.8 - 50;
        }
        else
        {
            money = money * 0.8;
        }
    }
    if (money > 0)
    {
        printf("%.2lf\n", money);
    }
    else
    {
        printf("0.00\n");
    }
    return 0;
}