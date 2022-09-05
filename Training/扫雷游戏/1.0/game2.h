#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define BOOM_COUNT 10
void init_board(char board[ROWS][COLS], int row, int col, int set);

void print_board(char board[ROWS][COLS], int row, int col);

void set_boom(char board[ROWS][COLS], int row, int col);

void find_boom(char boom[ROWS][COLS], char board[ROWS][COLS], int row, int col);