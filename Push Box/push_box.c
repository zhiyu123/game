#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<Windows.h>
int map1[13][14] = {															//创建一个地图
	{ 0,0,0,0,2,2,2,2,2,2,0,0,0,0 },					// 0: 空地		
	{ 0,0,0,0,2,0,0,0,0,2,0,0,0,0 },					// 1: 目的地  ☆
	{ 0,2,2,2,2,0,0,0,0,2,2,2,2,2 },					// 2: 墙壁    ■
	{ 0,2,0,0,0,2,0,0,0,0,0,0,0,2 },					// 4: 箱子	  □
	{ 0,2,0,4,0,0,0,4,0,0,0,4,0,2 },					// 8: 玩家    ♀
	{ 0,2,0,0,0,2,2,0,2,2,2,2,2,2 },					// 16:箱子已在目的地  ★
	{ 2,2,2,2,0,0,0,0,0,0,0,0,0,2 },					// 32:人在目的地上  ♂
	{ 2,0,0,0,0,0,2,0,0,0,8,0,0,2 },
	{ 2,0,4,0,0,0,2,0,2,2,2,2,2,2 },
	{ 2,2,0,0,0,0,2,0,2,0,1,1,2,0 },
	{ 0,2,0,2,0,0,0,0,0,0,1,1,2,0 },
	{ 0,2,0,0,0,0,2,2,0,0,0,0,2,0 },
	{ 0,2,2,2,2,2,2,2,2,2,2,2,2,0 }
};

void init_map1()									//初始化该地图
{
	int row;
	int col;
	for (row = 0; row < sizeof(map1) / sizeof(map1[0]); row++)
	{
		printf("     ");
		for (col = 0; col < sizeof(map1[0]) / sizeof(map1[0][0]); col++)
		{
			switch (map1[row][col])
			{
			case 0:
				printf("%s", "  ");
				break;
			case 1:
				printf("%s", "☆");
				break;
			case 2:
				printf("%s", "■");
				break;
			case 4:
				printf("%s", "□");
				break;
			case 8:
				printf("%s", "♀");
				break;
			case 16:
				printf("%s", "★");
				break;
			case 32:
				printf("%s", "♂");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}
int is_win_map1(void)
{
	int row;
	int col;
	int num = 0;
	for (row = 0; row < sizeof(map1) / sizeof(map1[0]); row++)
	{
		for (col = 0; col < sizeof(map1[0]) / sizeof(map1[0][0]); col++)
		{
			if (map1[row][col] == 4)
				num++;
		}
	}
	if (num == 0)
	{
		printf("游戏结束，恭喜你过关！\n");
		return 0;
	}
	return 1;
}
void player_game_map1(int row, int col)
{
	int perrow, percol;
	int i;
	int j;
	for (i = 0; i < sizeof(map1) / sizeof(map1[0]); i++)
	{
		for (j = 0; j < sizeof(map1[0]) / sizeof(map1[0][0]); j++)
		{
			if (map1[i][j] == 8 || map1[i][j] == 32)
			{
				perrow = i;
				percol = j;
			}
		}
	}
	if (map1[perrow + row][percol + col] == 0)
	{
		if (map1[perrow][percol] == 32)
		{
			map1[perrow + row][percol + col] = 8;
			map1[perrow][percol] = 1;
		}
		else
		{
			map1[perrow + row][percol + col] = 8;
			map1[perrow][percol] = 0;
		}
		return;
	}
	if (map1[perrow + row][percol + col] == 1)
	{
		if (map1[perrow][percol] == 32)
		{
			map1[perrow + row][percol + col] = 32;
			map1[perrow][percol] = 1;
		}
		else
		{
			map1[perrow + row][percol + col] = 32;
			map1[perrow][percol] = 0;
		}
		return;
	}
	if (map1[perrow + row][percol + col] == 4)
	{
		if (map1[perrow + row + row][percol + col + col] == 0)
		{
			map1[perrow + row + row][percol + col + col] = 4;
			map1[perrow + row][percol + col] = 8;
			map1[perrow][percol] = 0;
		}
		if (map1[perrow + row + row][percol + col + col] == 1)
		{
			map1[perrow + row + row][percol + col + col] = 16;
			map1[perrow + row][percol + col] = 8;
			map1[perrow][percol] = 0;
		}
		return;
	}
	if (map1[perrow + row][percol + col] == 16)
	{
		if (map1[perrow][percol] == 32
			&& map1[perrow + row + row][percol + col + col] == 1)
		{
			map1[perrow + row + row][percol + col + col] = 16;
			map1[perrow + row][percol + col] = 32;
			map1[perrow][percol] = 1;
		}
		if (map1[perrow][percol] == 32
			&& map1[perrow + row + row][percol + col + col] == 0)
		{
			map1[perrow + row + row][percol + col + col] = 4;
			map1[perrow + row][percol + col] = 32;
			map1[perrow][percol] = 1;
			return;
		}
		if (map1[perrow + row + row][percol + col + col] != 16 && map1[perrow + row + row][percol + col + col] != 2)
		{
			map1[perrow + row + row][percol + col + col] = 16;
			map1[perrow + row][percol + col] = 32;
			map1[perrow][percol] = 0;
		}
		return;
	}
}
int main()
{
	int a;
	system("mode con cols=40 lines=15");
	system("color 5e");
	init_map1();
	do
	{
		switch (getch())
		{
		case 'w':
			player_game_map1(-1, 0);
			break;
		case 's':
			player_game_map1(1, 0);
			break;
		case 'a':
			player_game_map1(0, -1);
			break;
		case 'd':
			player_game_map1(0, 1);
			break;
		default:
			printf("输入错误\n");
			break;
		}
		system("cls");
		init_map1();
	} while (is_win_map1());
	system("pause");
	return 0;
}

