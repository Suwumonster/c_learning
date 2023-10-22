#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// ******************************
// ���ߣ�suwu
// ����޸�ʱ�䣺2023/10/22 21:49
// ******************************
#define N 2 //���庢�Ӹ���

typedef int BTDataType; //���������ݵ�����

typedef struct BinaryTree//���Ľڵ�
{
	BTDataType val;
	struct BinaryTree* child[N];
}BT;

// ��������BTBuyNode
// �������ܣ�����һ�����ڵ㣬����ָ��ȫ�ÿգ�������x���룬��󷵻�
// ��������������x
// �����������ͼ����ݣ�BT* ���ڵ� 
BT* BTBuyNode(BTDataType x);

// ��������visit
// �������ܣ���ӡ���ڵ������
// �������������ڵ�ָ��
// �����������ͼ����ݣ��� 
void visit(BT* cur);

// ��������BTorder
// �������ܣ����ܲ�ͬ��modeֵ��ִ�в�ͬ����ȱ���  mode 0 1 2�ֱ���� ǰ�� ���� ����
// ��������������ָ�룬modeֵ
// �����������ͼ����ݣ��� 
void BTorder(BT* root, int mode);

// ��������BTNodesum
// �������ܣ�������ܵĽڵ����
// ��������������ָ��
// �����������ͼ����ݣ�int ���Ľڵ����
int BTNodesum(BT* root);

// ��������BTLeaveNodesum
// �������ܣ��������Ҷ�ӽڵ����
// ��������������ָ��
// �����������ͼ����ݣ�int ����Ҷ�ӽڵ����
int BTLeaveNodesum(BT* root);

// ��������BTHeight
// �������ܣ�������ĸ߶�/��� �������1��
// ��������������ָ��
// �����������ͼ����ݣ�int �������/�߶�
int BTHeight(BT* root);

// ��������BTLayerNodesum
// �������ܣ��������k��Ľڵ����
// ��������������ָ��
// �����������ͼ����ݣ�int ����k��ڵ����
int BTLayerNodesum(BT* root, int k);
