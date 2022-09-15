#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}
double avrege(int arr[])
{
    qsort(arr, 7, sizeof(arr[0]), cmp);
    return (arr[1] + arr[2] + arr[3] + arr[4] + arr[5]) / 5.0;
}
int main()
{
    int arr[7] = { 0 };
    while (scanf("%d", &arr[0]) != EOF)
    {
        for (int i = 1; i < 7; i++)
        {
            scanf("%d", &arr[i]);
        }
        double num = avrege(arr);
        printf("%.2f\n", num);
    }

    return 0;
}