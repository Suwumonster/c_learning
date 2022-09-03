#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("****************************\n");
	printf("*****      1. play     *****\n");
	printf("*****      0. exit     *****\n");
	printf("****************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	srand((unsigned int)(time(NULL)));
	//初始化棋盘
	init_board(board, ROW, COL);
	
	while (1)
	{
		//打印棋盘
		print_board(board, ROW, COL);

		//玩家下棋
		player_move(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')//不继续
		{
			break;
		}

		//打印棋盘
		print_board(board, ROW, COL);
		

		//电脑下棋
		computer_move(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')//不继续
		{
			break;
		}
	}

	//游戏状态：
	//1.玩家赢 - *
	//2.电脑赢 - #
	//3.平局 - Q
	//4.游戏继续 - C
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

int main()
{
	int input;
	do
	{ 
		menu();
		printf("请选择：");
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
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}