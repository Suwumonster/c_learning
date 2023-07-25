#define _CRT_SECURE_NO_WARNINGS 1
//*********************************
// ���ߣ�suwu
// ����: vs2019 win10
// ����޸�ʱ�䣺2023/7/25 16:58
//*********************************

// ˼·һ �ռ任ʱ�� ���������� �ϲ�˳�� ��ǰ����(������Ŀ)

// ˼·�� ����ϲ� �ϲ�������һ�����鵱�� �����ڸ������� ��ָ��

// �������ƣ�merge
// �������ܣ��ϲ������������鲢�뵽��һ��������
// ��������������һ�׵�ַ������һ��С������һ��������������׵�ַ���������С�������������
// �������ͼ����ݣ�void
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