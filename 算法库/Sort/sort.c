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
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
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


void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


