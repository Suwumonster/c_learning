#define _CRT_SECURE_NO_WARNINGS 1
int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int j = 1;
    int num = numsSize;
    while (j < numsSize)
    {
        if (nums[i] != nums[j])
        {
            nums[i + 1] = nums[j];
            i++;
            j++;
            continue;
        }
        j++;
        num--;
    }
    return num;
}