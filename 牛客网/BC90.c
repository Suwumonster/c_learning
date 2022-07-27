#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[10][10] = { 0 };
int main()
{
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    int sum = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] > 0)
            {
                sum += arr[i][j];
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}