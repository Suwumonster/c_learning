#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// 作者：suwu
// 环境: vs2019 win10
// 最后修改时间：2023/7/25 16:58
//*********************************

// 思路一 空间换时间 开辟新数组 合并顺序 从前往后(不符题目)

// 思路二 逆向合并 合并到其中一个数组当中 不存在覆盖问题 三指针

// 函数名称：merge
// 函数功能：合并两个有序数组并入到第一个数组中
// 函数参数：数组一首地址，数组一大小，数组一数据量，数组二首地址，数组二大小，数组二数据量
// 返回类型及内容：void
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int src1 = m - 1, src2 = n - 1;
    int dst =  m + n - 1;

    while (src1 >= 0 && src2 >= 0)
    {
        if (nums1[src1] < nums2[src2])
        {
            nums1[dst] = nums2[src2];
            dst--;
            src2--;
        }
        else
        {
            nums1[dst] = nums1[src1];
            dst--;
            src1--;
        }
    }
    while (src2 >= 0)
    {
        nums1[dst] = nums2[src2];
        dst--;
        src2--;
    }
}