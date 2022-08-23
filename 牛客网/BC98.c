#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[50] = { 0 };
int main()
{
    int n = 0;
    int i = 0;
    int num = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &num);
    for (i = 0; i < n; i++)
    {
        if (arr[i] != num)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}