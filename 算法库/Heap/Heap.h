#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


// ******************************
// ���ߣ�suwu
// ����޸�ʱ�䣺2023/10/19 23:39
// ******************************
typedef int HeapDatatype;//���ڴ洢��������

typedef struct HEAP//��
{
	HeapDatatype* a;
	int size;
	int capicity;
}HP;

// ��������heapinit
// �������ܣ���ʼ���ѣ�ָ���ÿգ�size capicity��0
// ������������ָ��
// �����������ͼ����ݣ���
void heapinit(HP* php);

// ��������heapdestroy
// �������ܣ����ٶѣ��ͷ�ָ�룬ָ���ÿգ�size capicity��0
// ������������ָ��
// �����������ͼ����ݣ���
void heapdestroy(HP* php);

// ��������heappush
// �������ܣ�ѹ�ѣ���x������У������ֶѵ�����
// ������������ָ�룬����x
// �����������ͼ����ݣ���
void heappush(HP* php, HeapDatatype x);

// ��������heappop
// �������ܣ��ѶѶ�������������һ�����ݽ�������ɾ�����һ�����ݣ����ֶѵ�����
// ������������ָ��
// �����������ͼ����ݣ���
void heappop(HP* php);

// ��������heaptop
// �������ܣ�ȡ���Ѷ�����
// ������������ָ��
// �����������ͼ����ݣ�HeapDatatype �Ѷ�����
HeapDatatype heaptop(HP* php);

// ��������heapsize
// �������ܣ�����������ݸ���������
// ������������ָ��
// �����������ͼ����ݣ�int �������ݸ���
int heapsize(HP* php);

// ��������heapempty
// �������ܣ��ж϶��Ƿ�Ϊ��
// ������������ָ��
// �����������ͼ����ݣ�int ��/��
int heapempty(HP* php);