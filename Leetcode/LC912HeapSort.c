#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void AdjustDown(int* a, int parent, int n)
{
    int child = 2 * parent + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child + 1] > a[child])
        {
            child++;
        }
        if (a[child] > a[parent])
        {
            swap(&a[child], &a[parent]);
        }
        else
        {
            break;
        }
        parent = child;
        child = 2 * parent + 1;
    }
}
void HeapSort(int* a, int n)
{
    //½¨´ó¶Ñ
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDown(a, i, n);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        AdjustDown(a, 0, i);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* tmp = (int*)malloc(sizeof(int) * numsSize);
    memcpy(tmp, nums, sizeof(int) * numsSize);
    HeapSort(tmp, numsSize);
    return tmp;
}