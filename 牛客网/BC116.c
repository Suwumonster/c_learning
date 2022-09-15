#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[10] = { 0 };
void fun(int n, int i)
{
    if (n < 10)
    {
        if (n % 2 == 1)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
        return;
    }
    if (n % 10 % 2 == 1)
    {
        arr[i] = 1;
    }
    else
    {
        arr[i] = 0;
    }
    fun(n / 10, i - 1);
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    fun(n, 9);
    n = 0;
    for (int i = 0; i < 10; i++)
    {
        n = 10 * n + arr[i];
    }
    printf("%d\n", n);
    return 0;
}