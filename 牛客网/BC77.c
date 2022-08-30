#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[50] = { 0 };
int main()
{
    int n = 0;
    int i = 0;
    int num = 0;
    int is_print = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &num);
    for (i = 0; i < n; i++)
    {
        if (num < arr[i] && is_print == 0)
        {
            printf("%d ", num);
            is_print = 1;
        }
        printf("%d ", arr[i]);
    }
    return 0;
}