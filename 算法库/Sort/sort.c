#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
#include "stack.h"

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

int midNum(int* a, int start, int end)//快排优化，三数取中
{
	int mid = (start + end) / 2;
	if (a[start] > a[mid])
	{
		if (a[mid] > a[end]) // a[start] > a[mid] > a[end]
		{
			return mid;
		}
		else if (a[start] > a[end]) // a[start] > a[end] > a[mid]
		{
			return end;
		}
		else//a[end] > a[start] > a[mid]
		{
			return start;
		}
	}
	else// a[mid] > a[start]
	{
		if (a[start] > a[end])//a[mid] > a[start] > a[end]
		{
			return start;
		}
		else if (a[mid] > a[end])//a[mid] > a[end] > a[start]
		{
			return end;
		}
		else//a[end] > a[mid] > a[start]
		{
			return mid;
		}
	}
}

int PartSort1(int* a, int start, int end)//Hoare单趟快排思想
{
	int left = start;
	int right = end;

	//三数取中优化，避免有序情况，最坏情况
	int keyi = midNum(a, start, end);
	swap(&a[left], &a[keyi]);
	keyi = left;

	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[keyi], &a[right]);
	keyi = right;
	return keyi;
}

int PartSort2(int* a, int start, int end)//填坑法单趟快排思想
{
	int left = start;
	int right = end;

	//三数取中优化，避免有序情况，最坏情况
	int midi = midNum(a, start, end);
	swap(&a[left], &a[midi]);
	int key = a[left];
	int hole = left;

	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		swap(&a[hole], &a[right]);
		hole = right;

		while (left < right && a[left] <= key)
		{
			left++;
		}
		swap(&a[hole], &a[left]);
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int start, int end)//前后指针单趟快排思想
{
	int cur = start + 1;
	int prev = start;
	int keyi = start;
	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	swap(&a[keyi], &a[prev]);
	keyi = prev;
	return keyi;
}

void PartSort4(int* a, int start, int end, int *left, int *right)//三指针单趟快排思想 三路划分
{
	int cur = start + 1;
	*left = start;
	*right = end;
	
	int tmp = start + rand() % (end - start + 1);
	swap(&a[tmp], &a[start]);
	int key = a[start];

	while (cur <= *right)
	{
		if (a[cur] < key)
		{
			swap(&a[cur], &a[*left]);
			cur++;
			(*left)++;
		}
		else if (a[cur] > key)
		{
			swap(&a[cur], &a[*right]);
			(*right)--;
		}
		else// a[cur] == key
		{
			cur++;
		}
	}
	
	
}
void _QuickSort(int* a, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	//if ((end - start + 1) < 15)//小区间优化，减少栈帧压力
	//{
	//	InsertSort(a + start, end - start + 1);
	//}
	//else
	{
		int left = start;
		int right = end;
		PartSort4(a, start, end, &left, &right);

		_QuickSort(a, start, left - 1);
		_QuickSort(a, right + 1, end);
	}

}

void QuickSort(int* a, int n)
{
	srand((unsigned int)time(NULL));
	_QuickSort(a, 0, n - 1);
}

void _QuickSortNonR(int* a, int start, int end)//也可以用队列实现
{
	ST st;
	stackinit(&st);
	stackpush(&st, start);
	stackpush(&st, end);
	while (!stackempty(&st))
	{
		int right = stacktop(&st);
		stackpop(&st);
		int left = stacktop(&st);
		stackpop(&st);
		int keyi = PartSort3(a, left, right);
		if (left < keyi - 1)
		{
			stackpush(&st, left);
			stackpush(&st, keyi - 1);
		}
		if (keyi + 1 < right)
		{
			stackpush(&st, keyi + 1);
			stackpush(&st, right);
		}
	}
	stackdestroy(&st);
}

//需要包含头文件 stack.h 栈实习非递归快排
void QuickSortNonR(int* a, int n)
{
	_QuickSortNonR(a, 0, n - 1);
}

void _MergeSort(int* a, int start, int end, int *tmp)
{
	if (start >= end)
	{
		return;
	}

	//分解排序
	int mid = (start + end) / 2;
	_MergeSort(a, start, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	int i = start;
	while (start1 <= end1 && start2 <= end2)
	{
		if (a[start1] < a[start2])
		{
			tmp[i] = a[start1];
			i++;
			start1++;
		}
		else
		{
			tmp[i] = a[start2];
			i++;
			start2++;
		}
	}

	while (start1 <= end1)
	{
		tmp[i] = a[start1];
		i++;
		start1++;
	}
	while (start2 <= end2)
	{
		tmp[i] = a[start2];
		i++;
		start2++;
	}
	memcpy(a + start, tmp + start, sizeof(int) * (end - start + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	int rangeN = 1;//归并时一组的数据个数
	while (rangeN < n)
	{
		for (int j = 0; j < n; j += 2 * rangeN)
		{
			int start1 = j, end1 = j + rangeN - 1;
			int start2 = j + rangeN, end2 = j + 2 * rangeN - 1;
			if (end1 >= n)// end1 start2 end2 都越界
			{
				end1 = n - 1;
				//第二组需要构造不存在的数组
				start2 = n;
				end2 = n - 1;
			}
			else if (start2 >= n)// start2 end2 都越界
			{
				//第二组需要构造不存在的数组
				start2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)//end2 越界
			{
				end2 = n - 1;
			}
			int i = j;//控制tmp数组下标
			while (start1 <= end1 && start2 <= end2)
			{
				if (a[start1] < a[start2])
				{
					tmp[i] = a[start1];
					i++;
					start1++;
				}
				else
				{
					tmp[i] = a[start2];
					i++;
					start2++;
				}
			}

			while (start1 <= end1)
			{
				tmp[i] = a[start1];
				i++;
				start1++;
			}
			while (start2 <= end2)
			{
				tmp[i] = a[start2];
				i++;
				start2++;
			}
			memcpy(a + j, tmp + j, sizeof(int) * (end2 - j + 1));
		}
		rangeN *= 2;
	}
	free(tmp);
	tmp = NULL;
}