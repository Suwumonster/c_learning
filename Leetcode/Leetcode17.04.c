#define _CRT_SECURE_NO_WARNINGS 1
int missingNumber(int* nums, int numsSize) {
    int hash[numsSize + 1];
    int i = 0;
    for (i = 0; i < numsSize + 1; i++)
    {
        hash[i] = 0;
    }
    for (i = 0; i < numsSize; i++)
    {
        hash[nums[i]] = 1;
    }
    for (i = 0; i < numsSize + 1; i++)
    {
        if (hash[i] != 1)
        {
            return i;
        }
    }
    return -1;
}