#define _CRT_SECURE_NO_WARNINGS 1
//��������
void reverse(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize / 2; i++)
    {
        int tmp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = tmp;
    }
}
//����������תk��
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    reverse(nums, numsSize - k);
    reverse(nums + numsSize - k, k);
    reverse(nums, numsSize);
}