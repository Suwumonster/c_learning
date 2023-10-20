#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

// ******************************
// ���ߣ�suwu
// ����޸�ʱ�䣺2023/10/20 21:08
// ******************************


//��������Ҫ���õ�heap.h����Ķ����µ����㷨adjustdown
//�Լ����ϵ����㷨adjustup �ͽ��������㷨swap

void HeapSort(HeapDatatype* a, int n)
{
	//����
	//���򽨴�� ����С�� 
	//���µ�������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		adjustdown(a, n, i);
	}

	//��Heappop˼�� �ѶѶ����ݷŵ���󣬰�ǰn - 1�����¿��ɶѣ����µ���
	//ѭ��n��
	int newN = n;
	for (int i = 0; i < n; i++)
	{
		swap(&a[0], &a[newN - 1]);
		newN--;
		adjustdown(a, newN, 0);
	}
}
