#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// 作者：suwu
// 环境: vs2019 win10
// 最后修改时间：2023/7/25 16:29
//*********************************

//思路一 双指针 类似LC27

// 函数名称：removeDuplicates
// 函数功能：删除有序数组中的重复数据，返回去重后的元素个数
// 函数参数：数组指针，元素个数
// 返回类型及内容：int，去重后的元素个数
int removeDuplicates(int* nums, int numsSize) {
    int src = 0;
    int dst = 0;

    while (src < numsSize)
    {
        if (nums[src] == nums[dst])
        {
            src++;
        }
        else
        {
            dst++;
            nums[dst] = nums[src];
        }
    }
    return dst + 1;
}