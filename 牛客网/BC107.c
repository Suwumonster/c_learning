#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[10][10] = { 0 };
int mark[10][10] = { 0 };//记录arr数组是否交换过 1为交换过 0为没有交换过
void reverse(int n, int m)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mark[i][j] == 0 && mark[j][i] == 0)
            {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
                mark[i][j] = 1;
                mark[j][i] = 1;
            }
        }
    }
}
int main()
{
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    reverse(n, m);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}