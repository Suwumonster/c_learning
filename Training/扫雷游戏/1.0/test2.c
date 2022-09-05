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
	printf("开始游戏\n");
	char board[ROWS][COLS] = { 0 };
	char boom[ROWS][COLS] = { 0 };

	//初始化
	//棋盘初始化为*
	init_board(board, ROWS, COLS, '*');
	//雷棋盘初始化为 '0'
	init_board(boom, ROWS, COLS, '0');
	//埋雷
	set_boom(boom, ROW, COL);
	//打印棋盘
	print_board(board, ROW, COL);
	//排雷
	find_boom(boom, board, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);
	
	return 0;
}