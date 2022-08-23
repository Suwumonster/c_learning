#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
long long fun(long long n, long long m)
{
    if (m == 0)
    {
        return n;
    }
    return fun(m, n % m);
}
int main()
{
    long long n = 0;
    long long m = 0;
    long long ret = 0;
    scanf("%d %d", &n, &m);
    ret = fun(n, m);
    printf("%lld\n", ret + n * m / ret);
    return 0;
}