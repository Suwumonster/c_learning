#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[50] = { 0 };
int fun1(int n)
{
    int i = 0;
    int is_sorted = 1;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            is_sorted = 0;
            break;
        }
    }
    return is_sorted;
}
int fun2(int n)
{
    int i = 0;
    int is_sorted = 1;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            is_sorted = 0;
            break;
        }
    }
    return is_sorted;
}
int main()
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (fun1(n) || fun2(n))
    {
        printf("sorted\n");
    }
    else
    {
        printf("unsorted\n");
    }
    return 0;
}