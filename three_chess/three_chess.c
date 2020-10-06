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
			printf("��Ϸ������\n");
			break;
		}
		show_board(board, ROW, COL);
		player_move(board, ROW, COL);
		if (is_win(board, ROW, COL) != ' ')
		{
			printf("��Ϸ������\n");
			break;
		}
		show_board(board, ROW, COL);
	}
	if (is_win(board, ROW, COL) == 'X')
	{
		printf("����Ӯ��\n");
	}
	else if (is_win(board, ROW, COL) == 'O')
	{
		printf("���Ӯ��\n");
	}
	else if (is_win(board, ROW, COL) == 'P')
	{
		printf("ƽ�֣�\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("�����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}