#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// ���ߣ�suwu
// ����: vs2019 win10
// ����޸�ʱ�䣺2023/7/25 16:29
//*********************************

//˼·һ ˫ָ�� ����LC27

// �������ƣ�removeDuplicates
// �������ܣ�ɾ�����������е��ظ����ݣ�����ȥ�غ��Ԫ�ظ���
// ��������������ָ�룬Ԫ�ظ���
// �������ͼ����ݣ�int��ȥ�غ��Ԫ�ظ���
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