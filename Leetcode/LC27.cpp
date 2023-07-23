#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// ���ߣ�suwu
// ����: vs2019 win10
// ����޸�ʱ�䣺2023/7/23 16:31
//*********************************

// �������ƣ�Find
// �������ܣ�����˳�����������ݣ���val��ͬ�ĵ�һ�����ݵ��±꽫�����ء�
// ��������������ָ�룬Ԫ�ظ�������ʼ�����±꣬�ȶ�ֵ
// �������ͼ����ݣ���val��ͬ�ĵ�һ�����ݵ��±꣬���û�ҵ��򷵻�-1
int Find(int* nums, int numsSize, int begin, int val);

// �������ƣ�Erase
// �������ܣ�ɾ���±�Ϊpos�����ݣ���������������и���
// ��������������ָ�룬Ԫ�ظ�������ʼ�����±�
// �������ͼ����ݣ�int��ɾ�����Ԫ�ظ���
int Erase(int* nums, int numsSize, int pos);


// �������ƣ�removeElement
// �������ܣ�ɾ��������val��ͬ�����ݣ�������ɾ�����Ԫ�ظ���
// ��������������ָ�룬Ԫ�ظ������ȶ�ֵ
// �������ͼ����ݣ�int��ɾ�����Ԫ�ظ���
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
    if (pos < 0 || pos >= numsSize)//posλ�ñ������
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