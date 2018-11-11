#define _CRT_SECURE_NO_WARNINGS

#include"saolei.h"

void Menu()
{
	int start = 0;
	printf("是否开始游戏？\n是：1\t否：0\n");
	scanf("%d",&start);
	if (start)
	{
		Game();
	}
	else
	{
		;
	}
}

void Init(char arr[ROWS][COLS], int row, int col, char s)
{
	memset(arr,s,row*col*sizeof(arr[0][0]));
}

void Game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Init(mine, ROWS, COLS, '0');
	Init(show, ROWS, COLS, '*');
	printf("-------------------\n");
	DisPlay(show, ROW, COL);
	printf("-------------------\n");
	SetMine(mine,ROW,COL);
	/*DisPlay(mine,ROW,COL);*/
	FindMine(mine, show, ROW, COL);
}

void DisPlay(char arr[ROWS][COLS], int row, int col)//打印
{
	for (int i = 0; i <= ROW; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i );
		for (int j = 1; j <= col; j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS],int row,int col)//布雷
{
	int num = MINE_NUM;
	while (num)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			num--;
		}
	}
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int once = 0;
	while (1)
	{
		printf("输入坐标：");
		scanf("%d%d", &x, &y);
		if (once == 0)
		{
			mine[x][y] = '0';
			if (mine[x][y] == '1')
			{
				int a = x;
				int b = y;
				while (1)
				{
					int a = rand() % row + 1;
					int b = rand() % col + 1;
					if (mine[a][b] == '0')
					{
						mine[a][b] = '1';
						break;
					}
				}
			}
			once++;
		}
		if (x <= ROW && y <= COL)
		{
			if (mine[x][y] == '1')
			{
				printf("炸死\n");
				DisPlay(mine, ROW, COL);
				return;
			}
			else
			{
				Open(mine, show, x, y);
				DisPlay(show, ROW, COL);
			}
			count = 0;
			for (int i = 1; i <= ROW; i++)
			{
				for (int j = 1
					; j <= COL; j++)
				{
					if (show[i][j] == '*')
					{
						count++;
					}
				}
			}
			if (count == MINE_NUM)
			{
				printf("排雷成功\n");
				return;
			}
		}
		else
		{
			printf("输入有误，重新输入：");
			continue;
		}
	}
}

int GetMine(char arr[ROWS][COLS], int x, int y)//统计雷数
{
	int count = 0;
	count = arr[x][y - 1] + arr[x - 1][y - 1] + arr[x - 1][y]
		+ arr[x - 1][y + 1] + arr[x][y + 1] + arr[x + 1][y + 1]
		+ arr[x + 1][y] + arr[x + 1][y - 1] - '0' * 8;
	return count;
}

void Open(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)//展开
{
	show[x][y] = GetMine(mine, x, y) + '0';
	if (show[x][y] == '0')
	{
		if (show[x][y-1]=='*')
		{
				Open(mine, show, x, y - 1);
		}
		if (show[x - 1][y - 1] == '*')
		{
				Open(mine, show, x - 1, y - 1);
		}
		if (show[x - 1 ][y] == '*')
		{
				Open(mine, show, x - 1, y);
		}
		if (show[x - 1][y + 1] == '*')
		{
				Open(mine, show, x - 1, y + 1);
		}
		if (show[x][y + 1] == '*')
		{
			Open(mine, show, x, y + 1);
		}
		if (show[x+1][y + 1] == '*')
		{
				Open(mine, show, x + 1, y + 1);
		}
		if (show[x+1][y] == '*')
		{
				Open(mine, show, x + 1, y);
		}
		if (show[x+1][y - 1] == '*')
		{
				Open(mine, show, x+1, y - 1);
		}
	}
	else
	{
		return;
	}
}