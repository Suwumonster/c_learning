#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int arr[100000] = { 0 };
int int_cmp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
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
    qsort(arr, n, sizeof(arr[0]), int_cmp);
    for (i = 0; i < n; i++)
    {
        if (i > 0)
        {
            if (arr[i] == arr[i - 1])
            {
                continue;
            }
        }
        printf("%d ", arr[i]);
    }
    return 0;
}