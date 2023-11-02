#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//O(N)  O(N^2)
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)//n - 1趟插入排序
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)//一趟插入排序
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else//遇到插入值较小的数  或者 到了数组最前面
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//O(N logN)  O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}


void SelectSort(int* a, int n)
{
	int mini = 0, maxi = 0;
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		mini = begin;
		maxi = begin;
		for (int i = begin + 1; i < end + 1; i++)
		{
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
			if (a[mini] > a[i])
			{
				mini = i;
			}
		}
		swap(&a[maxi], &a[end]);
		if (mini == end)
		{
			mini = maxi;
		}
		swap(&a[mini], &a[begin]);
		begin++;
		end--;
	}
	
}

void adjustdown(int* a, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{

		if (child + 1 < n && a[child + 1] > a[child])
		{
			child = child + 1;
		}

		if (a[child] > a[parent])//默认大堆，小堆改不等号
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* a, int n)
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

void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void BubbleSort(int* a, int n)
{
	for(int j = 1; j < n; j++)
	{
		int exchange = 0;
		for (int i = 0; i < n - j; i++)
		{
			if (a[i + 1] < a[i])
			{
				swap(&a[i + 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}

}

void _QuickSort(int* a, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int left = start;
	int right = end;
	int base = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[base])
		{
			right--;
		}
		while (left < right && a[left] <= a[base])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[base], &a[right]);

	_QuickSort(a, start, right - 1);
	_QuickSort(a, right + 1, end);
}

void QuickSort(int* a, int n)
{
	_QuickSort(a, 0, n - 1);
}