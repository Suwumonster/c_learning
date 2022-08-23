#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void fun(int n)
{
    if (n == 0)
    {
        return;
    }
    fun(n / 6);
    printf("%d", n % 6);
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    fun(n);
    return 0;
}