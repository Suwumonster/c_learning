#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

// ******************************
// 作者：suwu
// 最后修改时间：2023/10/20 21:08
// ******************************


//堆排序需要调用到heap.h里面的堆向下调整算法adjustdown
//以及向上调整算法adjustup 和交换数据算法swap

void HeapSort(HeapDatatype* a, int n)
{
	//建堆
	//升序建大堆 降序建小堆 
	//向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		adjustdown(a, n, i);
	}

	//用Heappop思想 把堆顶数据放到最后，把前n - 1个重新看成堆，向下调整
	//循环n次
	int newN = n;
	for (int i = 0; i < n; i++)
	{
		swap(&a[0], &a[newN - 1]);
		newN--;
		adjustdown(a, newN, 0);
	}
}
