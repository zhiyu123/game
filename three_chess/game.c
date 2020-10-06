#include"game.h"

void init_board(char board[ROW][COL], int row, int col)		//初始化棋盘
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

void show_board(char board[ROW][COL], int row, int col)			//展示棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void computer_move(char board[ROW][COL], int row, int col)	//电脑走
{
	int i = 0;
	int j = 0;
	printf("电脑走>\n" );
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = 'X';
			break;
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)	//玩家走
{
	int i = 0;
	int j = 0;
	printf("玩家走>\n");
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d %d", &i, &j);
		if (i >= 1 && i <= 3 && j >= 1 && j <= 3)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = 'O';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入！\n");
			}
		}
		else
		{
			printf("输入越界，请重新输入！\n");
		}
	}
}

int full_board(char board[ROW][COL], int row, int col)	//判断棋盘是否满
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

char is_win(char board[ROW][COL], int row, int col)		//判断是否赢了
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)		//行成三个
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0; j < col; j++)		//列成三个
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')	//斜线成三
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')	//斜线成三
	{
		return board[0][2];
	}
	if (full_board(board, ROW, COL))
	{
		return 'P';		//平局
	}
	return ' ';		//继续
 }




