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
		//��ӡ����
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)//����ָ��� | �����ұ�
			{
				printf("|");
			}
		}
		printf("\n");//����
		//��ӡ�ָ���---
		if (i < row - 1)//����ָ��� --- �� | ��������
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//����ָ��� | �����ұ�
				{
					printf("|");
				}
			}
			printf("\n");//����
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�������:\n");
	while (1)
	{
		printf("����������\n");
		scanf("%d %d", &x, &y);
		if ( x >= 1 && x <= row && y >= 1 && y <= col)//û��Խ��
		{
			if (board[x - 1][y - 1] == ' ')//λ��������
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else//λ��������
			{
				printf("��λ�������ӣ�����������\n");
			}
		}
		else//����Խ��
		{
			printf("�����������������\n");
		}
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	printf("��������:\n");
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')//��λ��������
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
	//�м��
	//��Ӯ��������һ���������� ���� ��ͬ�� �ַ�
	for (i = 0; i < row; i++)
	{
		char_count = 0;//ÿ�п�ʼǰ ��������
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')//����
			{
				char_count = 0;
				continue;
			}
			if (char_count == 0)//��ʼ�� con char
			{
				con_char = board[i][j];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[i][j])//������
			{
				char_count = 0;
				con_char = board[i][j];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[i][j])//����
			{
				char_count++;
			}
			if (char_count == 3)//Ӯ
			{
				print_board(board, ROW, COL);
				return con_char;
			}
		}
	}

	//�м��
	//��Ӯ��������һ���������� ���� ��ͬ�� �ַ�
	char_count = 0;
	for (j = 0; j < col; j++)
	{
		char_count = 0;//ÿ�п�ʼǰ ��������
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == ' ')//����
			{
				char_count = 0;
				continue;
			}
			if (char_count == 0)//��ʼ�� con char
			{
				con_char = board[i][j];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[i][j])//������
			{
				char_count = 0;
				con_char = board[i][j];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[i][j])//����
			{
				char_count++;
			}
			if (char_count == 3)//Ӯ
			{
				print_board(board, ROW, COL);
				return con_char;
			}
		}
	}

	//б�߼��
	// б��Ӯ��������һ�� б���� ������ ���� ��ͬ�� �ַ� 
	// 1.���Խ��� ��һ�� ��һ�� ���� ��ʼ ���
	// 2.���Խ��� ���һ�� �ڶ��� ���� ��ʼ ���
	// 3.���Խ��� ���һ�� ��һ�� ���� ��ʼ ���
	// 4.���Խ��� ��һ�� �ڶ��� ���� ��ʼ���
	
	for (i = 0, j = 0; j < col; j++)// 1.���Խ��� ��һ�� ��һ�� ���� ��ʼ ���
	{
		int x = i;
		int y = j;
		char_count = 0;
		while (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')//����
			{
				char_count = 0;
				x++;
				y--;
				continue;
			}
			if (char_count == 0)//��ʼ�� con char
			{
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[x][y])//������
			{
				char_count = 0;
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[x][y])//����
			{
				char_count++;
			}
			if (char_count == 3)//Ӯ
			{
				print_board(board, ROW, COL);
				return con_char;
			}
			x++;
			y--;
		}
	}

	for (i = 1, j = col - 1; i < row; i++)// 2.���Խ��� ���һ�� �ڶ��� ���� ��ʼ ���
	{
		int x = i;
		int y = j;
		char_count = 0;
		while (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')//����
			{
				char_count = 0;
				x++;
				y--;
				continue;
			}
			if (char_count == 0)//��ʼ�� con char
			{
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[x][y])//������
			{
				char_count = 0;
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[x][y])//����
			{
				char_count++;
			}
			if (char_count == 3)//Ӯ
			{
				print_board(board, ROW, COL);
				return con_char;
			}
			x++;
			y--;
		}
	}

	for (i = row - 1, j = 0; i >= 0; i--)// 3.���Խ��� ���һ�� ��һ�� ���� ��ʼ ���
	{
		int x = i;
		int y = j;
		char_count = 0;
		while (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')//����
			{
				char_count = 0;
				x++;
				y++;
				continue;
			}
			if (char_count == 0)//��ʼ�� con char
			{
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[x][y])//������
			{
				char_count = 0;
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[x][y])//����
			{
				char_count++;
			}
			if (char_count == 3)//Ӯ
			{
				print_board(board, ROW, COL);
				return con_char;
			}
			x++;
			y++;
		}
	}

	for (i = 0, j = 1; j < col; j++)// 4.���Խ��� ��һ�� �ڶ��� ���� ��ʼ���
	{
		int x = i;
		int y = j;
		char_count = 0;
		while (x >= 0 && x < row && y >= 0 && y < col)
		{
			if (board[x][y] == ' ')//����
			{
				char_count = 0;
				x++;
				y++;
				continue;
			}
			if (char_count == 0)//��ʼ�� con char
			{
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char != board[x][y])//������
			{
				char_count = 0;
				con_char = board[x][y];
				char_count++;
			}
			else if (char_count != 0 && con_char == board[x][y])//����
			{
				char_count++;
			}
			if (char_count == 3)//Ӯ
			{
				print_board(board, ROW, COL);
				return con_char;
			}
			x++;
			y++;
		}
	}

	//ƽ��
	if (is_full(board,ROW,COL))
	{
		print_board(board, ROW, COL);
		return 'Q';
	}

	//������Ϸ
	return 'C';
}

//�ж������Ƿ�����
//���˷��� 1�����򷵻� 0. 
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
