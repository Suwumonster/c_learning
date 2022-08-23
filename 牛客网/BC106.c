#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[10][10] = { 0 };
int main()
{
    int n = 0;
    int i = 0;
    int j = 0;
    int is_UTM = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            if (i > j && arr[i][j] != 0)
            {
                is_UTM = 0;
            }
        }
    }
    if (is_UTM == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}