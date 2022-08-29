#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr1[1000] = { 0 };
int arr2[1000] = { 0 };
void fun(int n, int m)
{
    int i = 0;
    int j = 0;
    for (i = 0, j = 0; ;)
    {
        while ((arr1[i] <= arr2[j] && i < n) || (j >= m && i < n))
        {
            printf("%d ", arr1[i]);
            i++;
        }
        while ((arr1[i] > arr2[j] && j < m) || (i >= n && j < m))
        {
            printf("%d ", arr2[j]);
            j++;
        }
        if (i >= n && j >= m)
        {
            break;
        }
    }
}
int main()
{
    int n = 0;
    int m = 0;
    int i = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    fun(n, m);
    return 0;
}