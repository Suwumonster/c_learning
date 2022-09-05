#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"

void init_board(char board[ROWS][COLS], int row, int col, int set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void print_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//´òÓ¡ÁÐÐòºÅ
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//´òÓ¡ÐÐÐòºÅ
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void set_boom(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	for (i = 0; i < BOOM_COUNT; )
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			i++;
		}
	}
}
int get_boom(char boom[ROWS][COLS], int x, int y)
{
	return (boom[x - 1][y]
		+ boom[x - 1][y - 1]
		+ boom[x][y - 1]
		+ boom[x + 1][y - 1]
		+ boom[x + 1][y]
		+ boom[x + 1][y + 1]
		+ boom[x][y + 1]
		+ boom[x - 1][y + 1] - 8*'0');
}
void find_boom(char boom[ROWS][COLS], char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < ROW*COL - BOOM_COUNT)
	{
		printf("ÇëÊäÈëÅÅÀ××ø±ê£º");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (boom[x][y] == '1')
			{
				printf("Äã²Èµ½À×£¬boom!ÓÎÏ·½áÊø\n");
				break;
			}
			else
			{
				int count = get_boom(boom, x, y);
				board[x][y] = count + '0';
				print_board(board, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë\n");
		}
	}
	if (win == ROW * COL - BOOM_COUNT)
	{
		printf("¹§Ï²Äã£¬ÅÅÀ×³É¹¦\n");
	}
}