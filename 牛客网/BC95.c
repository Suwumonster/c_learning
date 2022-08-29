#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[10000] = { 0 };
int main()
{
    int n = 0;
    int i = 0;
    int max = 0;
    int min = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (i == 0)
        {
            max = arr[0];
            min = arr[0];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    printf("%d\n", max - min);
    return 0;
}