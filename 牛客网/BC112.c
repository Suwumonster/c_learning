#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    long long n = 0;
    long long sum = 0;
    scanf("%d", &n);
    sum = n * (n + 1) / 2;
    printf("%lld\n", sum);
    return 0;
}