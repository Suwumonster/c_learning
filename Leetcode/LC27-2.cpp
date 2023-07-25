#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// 作者：suwu
// 环境: vs2019 win10
// 最后修改时间：2023/7/25 16:09
//*********************************

//思路2 空间换时间 不符题目要求

//思路3 双指针 src 跳过和val相同的数据
//             dst 一步一步跳步

// 函数名称：removeElement
// 函数功能：删除所有与val相同的数据，并返回删除后的元素个数
// 函数参数：数组指针，元素个数，比对值val
// 返回类型及内容：int，删除后的元素个数
int removeElement(int* nums, int numsSize, int val) {
    int src = 0;
    int dst = 0;
    while (src < numsSize)
    {
        if (nums[src] == val)
        {
            src++;
        }
        else
        {
            nums[dst] = nums[src];
            src++;
            dst++;
        }
    }
    return dst;
}