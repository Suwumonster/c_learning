#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int n = 0;
    int m = 0;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        sum += m;
    }
    printf("%d\n", sum);
    return 0;
}