#define _CRT_SECURE_NO_WARNINGS
#include"game.h"


void Initialization(int check[3][3])//初始化棋盘并打印
{
	for (int line = 0; line < 3; line++)
	{

		for (int column = 0; column < 3; column++)
		{
			check[line][column] = '_';
			printf("%c ", check[line][column]);
		}

		printf("\n");
	}

	printf("\n");

	printf("棋盘初始化完成\n");
}

void PrintingCheckerboard(int check[3][3])//打印刷新棋盘
{
	for (int line = 0; line < 3; line++)
	{

		for (int column = 0; column < 3; column++)
		{
			printf("%c ", check[line][column]);
		}

		printf("\n");

	}
	printf("\n");
}

int JudgeWinAndLose(int check[3][3])//判断输赢，判断胜利返回值为1，没有胜利为0
{
	for (int line = 0; line < 3; line++)//横向判断
	{

		if (   check[line][0] == check[line][1] 
			&& check[line][1] == check[line][2] 
			&& check[line][0] == check[line][2] 
			&& check[line][0] != '_')
		{
			printf("胜利\n");
			printf("游戏结束\n");
			return 1;
		}
	}


	for (int column = 0; column < 3; column++)//纵向判断
	{
		if (   check[0][column] == check[1][column] 
			&& check[1][column] == check[2][column] 
			&& check[0][column] == check[2][column] 
			&& check[0][column] != '_' )
		{
			printf("胜利\n");
			printf("游戏结束\n");
			return 1;
		}
	}


	if (check[0][0] == check[1][1] 
		&& check[1][1] == check[2][2] 
		&& check[0][0] == check[2][2] 
		&& check[1][1] != '_' 
		&& check[0][0] != '_' 
		&& check[2][2] != '_')//反斜向判断
	{
		printf("胜利\n");
		printf("游戏结束\n");
		return 1;
	}


	if (check[0][2] == check[1][1] 
		&& check[1][1] == check[2][0] 
		&& check[0][2] == check[2][0] 
		&& check[1][1] != '_' 
		&& check[0][2] != '_' 
		&& check[2][0] != '_')//斜向判断
	{
		printf("胜利\n");
		printf("游戏结束\n");
		return 1;
	}


	return 0;
}

void Player1(int check[3][3])//一号玩家
{
	int line = 0;
	int column = 0;//定义行列供玩家输入


	while (1)
	{
		printf("一号输入落子坐标(两数均在3以内)：");
		scanf("%d %d", &line, &column);


		if (line > 3 || column > 3)//不规则输入
		{
			printf("请按规则输入坐标！\n");
			continue;
		}


		line = line - 1;
		column = column - 1; //输入值 - 1适应数组下标


		if (check[line][column] == '_')
		{
			check[line][column] = '*';
			break;
		}
		else
		{
			printf("该坐标已有棋子！");
			continue;
		}
	}


	PrintingCheckerboard(check);//打印棋盘
}

void Player2(int check[3][3])//二号玩家
{
	int line = 0;
	int column = 0;


	while (1)
	{
		printf("二号输入落子坐标(两数均在3以内)：");
		scanf("%d %d", &line, &column);

		if (line > 3 || column > 3)//不规则输入
		{
			printf("请按规则输入坐标！\n");
			continue;
		}

		line = line - 1;
		column = column - 1;//输入值-1适应数组下标

		if (check[line][column] == '_')
		{
			check[line][column] = '%';
			break;
		}
		else
		{
			printf("该坐标已有棋子！");
			continue;
		}
	}


	PrintingCheckerboard(check);//打印棋盘
}

void Computer(int check[3][3])//电脑玩家
{
	int line = 0;
	int column = 0;//定义行列存放随机数
	printf("电脑走：\n");

	while (1)
	{
		line = rand() % 3;
		column = rand() % 3;//随机数生成行列
		if (check[line][column] == '_')
		{
			check[line][column] = 'X';
			PrintingCheckerboard(check);//打印棋盘
			break;
		}
	}

}

int Full(int check[3][3])//棋盘满员判断
{
	int count = 0;

	for (int line = 0; line < 3; line++)
	{

		for (int column = 0; column < 3; column++)
		{
			if (check[line][column] != '_')//对非‘_’符号计数，满9则棋盘已满
			{
				count++;
			}
		}

	}

	if (count == 9)//棋盘满返回值为1，否则为0
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void Game(int check[3][3],int ret)//游戏过程
{
	if (ret==0)//玩家双人对战
	{
		Initialization(check);//初始化棋盘

		while (1)
		{
			Player1(check);//一号玩家
			int x1 = JudgeWinAndLose(check);//输赢返回值，为1判断胜利，跳出循环
			if (x1)
			{
				break;
			}

			int x2 = Full(check);//满棋盘返回值，满返回值为1，游戏结束，跳出循环

			if (x2 == 1)
			{
				printf("棋盘已满\n");
				printf("游戏结束\n");
				break;
			}

			Player2(check);//二号玩家
			int y1 = JudgeWinAndLose(check);//输赢返回值，为1判断胜利，跳出循环
			if (y1)
			{
				break;
			}

			int y2 = Full(check);//满棋盘返回值，满返回值为1，游戏结束，跳出循环
			if (y2 == 1)
			{
				printf("棋盘已满\n");
				printf("游戏结束\n");
				break;
			}
		}//循环结束
	}

	else//与电脑对战
	{
		Initialization(check);//初始化棋盘
		while (1)
		{
			Player1(check);//一号玩家
			int x1 = JudgeWinAndLose(check);//输赢返回值
			if (x1== 1)
			{
				break;
			}

			int x2 = Full(check);//满棋盘返回值
			if (x2 == 1)
			{
				printf("棋盘已满\n");
				printf("游戏结束\n");
				break;
			}

			Computer(check);//电脑玩家
			int y1 = JudgeWinAndLose(check);//输赢返回值
			if (y1 == 1)
			{
				break;
			}

			int y2 = Full(check);//满棋盘返回值
			if (y2 == 1)
			{
				printf("棋盘已满\n");
				printf("游戏结束\n");
				break;
			}
		}//循环体结束
	}
	
}

int SelectionMenu()//选择菜单
{
	while (1)
	{
		int selection = 0;
		printf("选择与电脑对战还是玩家对战？\n玩家：0\t电脑：1\n");
		scanf("%d",&selection);//输入选择游戏方式

		if (selection == 1)
		{
			printf("与电脑对战\n");
			return 1;
		}
		else

		if (selection == 0)
		{
			printf("与玩家对战\n");
			return 0;
		}
		else
		{
			printf("请输入规定数字！");
			continue;
		}
	}

}

void Menu(int check[3][3]) //开始菜单
{
	while (1)
	{
		char play = '\0';
		printf("是否开始？是（y）,否（随意输入）\n");
		play = getchar();

		if (play == 'y')//判断是否开始
		{
			int ret = 0;
			ret = SelectionMenu();//选择游戏方式
			Game(check,ret);//游戏
		}
		else
		{
			printf("游戏结束\n");
		}

		while (getchar() != '\n')
		{
			fflush(stdin);//清空回车符
		}

		char again = '\0';
		printf("是否重新开始？是（y）,否（随意输入）\n");//重新开始选择
		again = getchar();

		if (again == 'y')
		{
			while (getchar() != '\n')
			{
				fflush(stdin);//清空回车符
			}
			continue;
		}

		else
		{
			break;
		}
	}
}


