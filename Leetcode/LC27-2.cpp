#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// ���ߣ�suwu
// ����: vs2019 win10
// ����޸�ʱ�䣺2023/7/25 16:09
//*********************************

//˼·2 �ռ任ʱ�� ������ĿҪ��

//˼·3 ˫ָ�� src ������val��ͬ������
//             dst һ��һ������

// �������ƣ�removeElement
// �������ܣ�ɾ��������val��ͬ�����ݣ�������ɾ�����Ԫ�ظ���
// ��������������ָ�룬Ԫ�ظ������ȶ�ֵval
// �������ͼ����ݣ�int��ɾ�����Ԫ�ظ���
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