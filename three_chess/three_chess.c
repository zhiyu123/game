#include"game.h"

void menu(void)
{
	printf("****************************\n");
	printf("*******   1.play  **********\n");
	printf("*******   0.exit  **********\n");
	printf("****************************\n");
}

void game(void)
{
	char flag = 0;
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	while (1)
	{	
		computer_move(board, ROW, COL);
		if (is_win(board, ROW, COL) != ' ')
		{
			printf("游戏结束！\n");
			break;
		}
		show_board(board, ROW, COL);
		player_move(board, ROW, COL);
		if (is_win(board, ROW, COL) != ' ')
		{
			printf("游戏结束！\n");
			break;
		}
		show_board(board, ROW, COL);
	}
	if (is_win(board, ROW, COL) == 'X')
	{
		printf("电脑赢！\n");
	}
	else if (is_win(board, ROW, COL) == 'O')
	{
		printf("玩家赢！\n");
	}
	else if (is_win(board, ROW, COL) == 'P')
	{
		printf("平局！\n");
	}
	show_board(board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time((NULL)));
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
			printf("退出游戏！\n");
			break;
		default:
			printf("输入有误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}