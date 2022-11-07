#define _CRT_SECURE_NO_WARNINGS 1
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = nums1Size - 1;
    int p = m - 1;
    int q = n - 1;
    for (i = nums1Size - 1; p >= 0 && q >= 0; i--)
    {
        if (nums1[p] <= nums2[q])
        {
            nums1[i] = nums2[q];
            q--;
        }
        else
        {
            nums1[i] = nums1[p];
            p--;
        }
    }
    while (p == -1 && q >= 0)
    {
        nums1[i] = nums2[q];
        i--;
        q--;
    }
}