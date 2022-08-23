#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[30] = { 0 };
int fun(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (arr[n - 1] != -1)
    {
        return arr[n - 1];
    }
    return fun(n - 1) + fun(n - 2);
}
int main()
{
    memset(arr, -1, sizeof(arr));
    int n = 0;
    int num = 0;
    scanf("%d", &n);
    arr[0] = 1;
    arr[1] = 2;
    num = fun(n);
    printf("%d\n", num);
    return 0;
}