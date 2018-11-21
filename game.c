#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col, char set){
	memset(board, set, row*col*sizeof(board[0][0]));
}
void DisplayBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			printf("%c", board[i][j]); 
			if (j != COL - 1){
				printf("  |");
			}
			}
		printf("\n");
		if (i != ROW - 1){
			printf("---+---+---");
			printf("\n");
		}
	}
}
void PlayGame(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	while (1){
		int count = 0;
		while (1){
			printf("������������ӵ�����(�磺a,b):>");
			scanf("%d,%d", &i, &j);
			if (board[i - 1][j - 1] != ' '){
				printf("�������ѱ�����ռ��!���������룡\n");
			}
			if (i<1 || i>3 || j<1 || j>3){
				printf("��������������������룡\n");
			}
			else{
				break;
			}
		}
		printf("�����:\n");
		printf("\n");
		board[i - 1][j - 1] = 'X';
		DisplayBoard(board, ROW, COL);
		if ((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == 'X')
			|| (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == 'X')
			|| (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == 'X')
			|| (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == 'X')
			|| (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == 'X')
			|| (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == 'X')
			|| (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X')
			|| (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'X')){
			printf("��ϲ�㣬��Ӯ�ˣ�\n");
			break;
		}
		for (m = 0; m < ROW; m++){
			for (n = 0; n < COL; n++){
				if (board[m][n] == ' '){
					count++;
				}
			}
		}
		if (count == 0){
			printf("ƽ��!");
			break;
		}
		while (1){
			i = rand() % 3;
			j = rand() % 3;
			if (board[i][j] == ' '){
				break;
			}
		}
		board[i][j] = '*';
		printf("������:>\n");
		printf("\n");
		DisplayBoard(board, ROW, COL);
		if ((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == '*')
			|| (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == '*')
			|| (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == '*')
			|| (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == '*')
			|| (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == '*')
			|| (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == '*')
			|| (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == '*')
			|| (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == '*')){
			printf("���ź�������Ӯ��!\n");
			break;
		}
	}
}
