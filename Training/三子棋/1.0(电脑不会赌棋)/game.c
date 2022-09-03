#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//打印棋子
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)//避免分割线 | 在最右边
			{
				printf("|");
			}
		}
		printf("\n");//换行
		//打印分割线---
		if (i < row - 1)//避免分割线 --- 和 | 在最下面
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//避免分割线 | 在最右边
				{
					printf("|");
				}
			}
			printf("\n");//换行
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋:\n");
	while (1)
	{
		printf("请输入坐标\n");
		scanf("%d %d", &x, &y);
		if ( x >= 1 && x <= row && y >= 1 && y <= col)//没有越界
		{
			if (board[x - 1][y - 1] == ' ')//位置无棋子
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else//位置有棋子
			{
				printf("该位置有棋子，请重新输入\n");
			}
		}
		else//棋子越界
		{
			printf("输入错误，请重新输入\n");
		}
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:\n");
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')//该位置无棋子
		{
			board[x][y] = '#';
			break;
		}
	}
}

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	char con_char = 0;
	int char_count = 0;
	//行检测
	//行赢的条件：一行中连续的 三个 相同的 字符
	for (i = 0; i < row; i++)
	{
		char_count = 0;//每行开始前 计数清零
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')//跳过
			{
				char_count = 0;
				continue;
			}
			if (char_count == 0)//初始化 con char
			{
				con_char = board[i][j];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[i][j])//不连续
			{
				char_count = 0;
				con_char = board[i][j];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[i][j])//连续
			{
				char_count++;
			}
			if (char_count == 3)//赢
			{
				print_board(board, ROW, COL);
				return con_char;
			}
		}
	}

	//列检测
	//列赢的条件：一列中连续的 三个 相同的 字符
	char_count = 0;
	for (j = 0; j < col; j++)
	{
		char_count = 0;//每列开始前 计数清零
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == ' ')//跳过
			{
				char_count = 0;
				continue;
			}
			if (char_count == 0)//初始化 con char
			{
				con_char = board[i][j];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[i][j])//不连续
			{
				char_count = 0;
				con_char = board[i][j];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[i][j])//连续
			{
				char_count++;
			}
			if (char_count == 3)//赢
			{
				print_board(board, ROW, COL);
				return con_char;
			}
		}
	}

	//斜线检测
	// 斜线赢的条件：一条 斜线中 连续的 三个 相同的 字符 
	// 1.副对角线 第一行 第一列 往右 开始 检测
	// 2.副对角线 最后一列 第二行 往下 开始 检测
	// 3.主对角线 最后一行 第一列 往上 开始 检测
	// 4.主对角线 第一行 第二列 往右 开始检测
	
	for (i = 0, j = 0; j < col; j++)// 1.副对角线 第一行 第一列 往右 开始 检测
	{
		int x = i;
		int y = j;
		char_count = 0;
		while (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')//跳过
			{
				char_count = 0;
				x++;
				y--;
				continue;
			}
			if (char_count == 0)//初始化 con char
			{
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[x][y])//不连续
			{
				char_count = 0;
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[x][y])//连续
			{
				char_count++;
			}
			if (char_count == 3)//赢
			{
				print_board(board, ROW, COL);
				return con_char;
			}
			x++;
			y--;
		}
	}

	for (i = 1, j = col - 1; i < row; i++)// 2.副对角线 最后一列 第二行 往下 开始 检测
	{
		int x = i;
		int y = j;
		char_count = 0;
		while (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')//跳过
			{
				char_count = 0;
				x++;
				y--;
				continue;
			}
			if (char_count == 0)//初始化 con char
			{
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[x][y])//不连续
			{
				char_count = 0;
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[x][y])//连续
			{
				char_count++;
			}
			if (char_count == 3)//赢
			{
				print_board(board, ROW, COL);
				return con_char;
			}
			x++;
			y--;
		}
	}

	for (i = row - 1, j = 0; i >= 0; i--)// 3.主对角线 最后一行 第一列 往上 开始 检测
	{
		int x = i;
		int y = j;
		char_count = 0;
		while (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')//跳过
			{
				char_count = 0;
				x++;
				y++;
				continue;
			}
			if (char_count == 0)//初始化 con char
			{
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[x][y])//不连续
			{
				char_count = 0;
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[x][y])//连续
			{
				char_count++;
			}
			if (char_count == 3)//赢
			{
				print_board(board, ROW, COL);
				return con_char;
			}
			x++;
			y++;
		}
	}

	for (i = 0, j = 1; j < col; j++)// 4.主对角线 第一行 第二列 往右 开始检测
	{
		int x = i;
		int y = j;
		char_count = 0;
		while (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')//跳过
			{
				char_count = 0;
				x++;
				y++;
				continue;
			}
			if (char_count == 0)//初始化 con char
			{
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[x][y])//不连续
			{
				char_count = 0;
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[x][y])//连续
			{
				char_count++;
			}
			if (char_count == 3)//赢
			{
				print_board(board, ROW, COL);
				return con_char;
			}
			x++;
			y++;
		}
	}

	//平局
	if (is_full(board,ROW,COL))
	{
		print_board(board, ROW, COL);
		return 'Q';
	}

	//继续游戏
	return 'C';
}

//判断棋盘是否满了
//满了返回 1，否则返回 0. 
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
