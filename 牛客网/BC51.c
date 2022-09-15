#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int is_triangle(int a, int b, int c)
{
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        return 0;
    }
    if (a == b && a == c)
    {
        return 1;
    }
    else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    while (scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        int ret = is_triangle(a, b, c);
        if (ret == 0)
        {
            printf("Not a triangle!\n");
        }
        else if (ret == 1)
        {
            printf("Equilateral triangle!\n");
        }
        else if (ret == 2)
        {
            printf("Isosceles triangle!\n");
        }
        else
        {
            printf("Ordinary triangle!\n");
        }
    }

    return 0;
}