#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"

void menu()
{
	printf("*****************************\n");
	printf("******     1. play     ******\n");
	printf("******     0. exit     ******\n");
	printf("*****************************\n");
}

void game()
{
	printf("��ʼ��Ϸ\n");
	char board[ROWS][COLS] = { 0 };
	char boom[ROWS][COLS] = { 0 };

	//��ʼ��
	//���̳�ʼ��Ϊ*
	init_board(board, ROWS, COLS, '*');
	//�����̳�ʼ��Ϊ '0'
	init_board(boom, ROWS, COLS, '0');
	//����
	set_boom(boom, ROW, COL);
	//��ӡ����
	print_board(board, ROW, COL);
	//����
	find_boom(boom, board, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}
	} while (input);
	
	return 0;
}