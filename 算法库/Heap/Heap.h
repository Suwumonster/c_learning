#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


// ******************************
// 作者：suwu
// 最后修改时间：2023/10/20 21:08
// ******************************

typedef int HeapDatatype;//堆内存储数据类型

typedef struct HEAP//堆
{
	HeapDatatype* a;
	int size;
	int capicity;
}HP;

// 函数名：heapinit
// 函数功能：初始化堆，指针置空，size capicity置0
// 函数参数：堆指针
// 函数返回类型及内容：空
void heapinit(HP* php);

// 函数名：heapdestroy
// 函数功能：销毁堆，释放指针，指针置空，size capicity置0
// 函数参数：堆指针
// 函数返回类型及内容：空
void heapdestroy(HP* php);

// 函数名：heappush
// 函数功能：压堆，把x存入堆中，并保持堆的性质
// 函数参数：堆指针，数据x
// 函数返回类型及内容：空
void heappush(HP* php, HeapDatatype x);

// 函数名：heappop
// 函数功能：把堆顶的数据与堆最后一个数据交换，并删除最后一个数据，保持堆的性质
// 函数参数：堆指针
// 函数返回类型及内容：空
void heappop(HP* php);

// 函数名：heaptop
// 函数功能：取出堆顶数据
// 函数参数：堆指针
// 函数返回类型及内容：HeapDatatype 堆顶数据
HeapDatatype heaptop(HP* php);

// 函数名：heapsize
// 函数功能：算出堆内数据个数并返回
// 函数参数：堆指针
// 函数返回类型及内容：int 堆内数据个数
int heapsize(HP* php);

// 函数名：heapempty
// 函数功能：判断堆是否为空
// 函数参数：堆指针
// 函数返回类型及内容：int 真/假
int heapempty(HP* php);

// 函数名：swap
// 函数功能：交换数据
// 函数参数：数据类型指针
// 函数返回类型及内容：空
void swap(HeapDatatype* a, HeapDatatype* b);

// 函数名：adjustup
// 函数功能：堆向上调整算法
// 函数参数：数据类型指针，向上调整的开始下标
// 函数返回类型及内容：空
void adjustup(HeapDatatype* a, int child);

// 函数名：adjustdown
// 函数功能：堆向下调整算法
// 函数参数：数据类型指针，数据个数，向下调整的开始下标
// 函数返回类型及内容：空
void adjustdown(HeapDatatype* a, int n, int parent);