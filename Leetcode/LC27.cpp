#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// 作者：suwu
// 环境: vs2019 win10
// 最后修改时间：2023/7/23 16:31
//*********************************

// 函数名称：Find
// 函数功能：查找顺序表里面的数据，和val相同的第一个数据的下标将被返回。
// 函数参数：数组指针，元素个数，开始查找下标，比对值
// 返回类型及内容：和val相同的第一个数据的下标，如果没找到则返回-1
int Find(int* nums, int numsSize, int begin, int val);

// 函数名称：Erase
// 函数功能：删除下标为pos的数据，并将数组整体进行覆盖
// 函数参数：数组指针，元素个数，开始查找下标
// 返回类型及内容：int，删除后的元素个数
int Erase(int* nums, int numsSize, int pos);


// 函数名称：removeElement
// 函数功能：删除所有与val相同的数据，并返回删除后的元素个数
// 函数参数：数组指针，元素个数，比对值
// 返回类型及内容：int，删除后的元素个数
int removeElement(int* nums, int numsSize, int val) {
    int pos = Find(nums, numsSize, 0, val);
    while (pos != -1)
    {
        numsSize = Erase(nums, numsSize, pos);
        pos = Find(nums, numsSize, pos, val);
    }
    return numsSize;
}

int Find(int* nums, int numsSize, int begin, int val)
{
    int i = begin;
    for (i = begin; i < numsSize; i++)
    {
        if (val == nums[i])
        {
            return i;
        }
    }
    return -1;
}

int Erase(int* nums, int numsSize, int pos)
{
    if (pos < 0 || pos >= numsSize)//pos位置必须合理
    {
        return numsSize;
    }
    int begin = 0;
    for (begin = pos; begin < numsSize - 1; begin++)
    {
        nums[begin] = nums[begin + 1];
    }
    return numsSize - 1;
}