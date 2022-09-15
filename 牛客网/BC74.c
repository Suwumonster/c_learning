#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int n = 0;
    int arr[7] = { 200, 202, 400, 403, 404, 500, 502 };
    char ch[7][30] = { "OK", "Accepted", "Bad Request", "Forbidden", "Not Found", "Internal Server Error", "Bad Gateway" };

    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < 7; i++)
        {
            if (n == arr[i])
            {
                printf("%s\n", ch[i]);
                break;
            }
        }
    }
    return 0;
}