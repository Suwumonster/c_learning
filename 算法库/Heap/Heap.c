#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void heapinit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capicity = 0;
}
void heapdestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capicity = 0;
}



void swap(HeapDatatype* a, HeapDatatype* b)
{
	HeapDatatype tmp = *a;
	*a = *b;
	*b = tmp;
}

void adjustup(HP* php, int child)
{
	assert(php);
	while (child > 0)
	{
		int parent = (child - 1) / 2;
		if (php->a[child] > php->a[parent])//默认是大堆，变成小堆只要改 > 为 <.
		{
			swap(&php->a[child], &php->a[parent]);
			child = parent;
		}
		else
		{
			break;
		}
	}
}

void heappush(HP* php, HeapDatatype x)
{
	assert(php);
	if (php->size == php->capicity)
	{
		int newcapicity = (php->a == NULL) ? 4 : 2 * php->capicity ;
		HeapDatatype* tmp = (HeapDatatype*)realloc(php->a, sizeof(HeapDatatype) * newcapicity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capicity = newcapicity;
	}
	php->a[php->size] = x;
	php->size++;
	adjustup(php, php->size - 1);
}

void adjustdown(HP* php, int parent)
{
	int child = 2 * parent + 1;
	while (child < php->size)
	{
		
		if (child + 1 < php->size && php->a[child] < php->a[child + 1])
		{
			child = child + 1;
		}

		if (php->a[parent] < php->a[child])//默认大堆，小堆改不等号
		{
			swap(&php->a[parent], &php->a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void heappop(HP* php)
{
	assert(php);
	assert(!heapempty(php));
	swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	adjustdown(php, 0);
}

HeapDatatype heaptop(HP* php)
{
	assert(php);
	assert(!heapempty(php));
	return php->a[0];
}

int heapsize(HP* php)
{
	assert(php);
	return php->size;
}

int heapempty(HP* php)
{
	assert(php);
	if (php->size == 0)
	{
		return 1;
	}
	return 0;
}