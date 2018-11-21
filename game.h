#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col, char set);
void DisplayBoard(char board[ROW][COL], int row,int col);
void PlayGame(char board[ROW][COL], int row, int col);
