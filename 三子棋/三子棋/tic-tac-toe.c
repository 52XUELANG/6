#define _CRT_SECURE_NO_WARNINGS
#include"game.h"




int main()
{
	int check[3][3] = {0};//定义并初始化“棋盘”
	srand((unsigned int)time(NULL));//利用时间产生随机数
	Menu(check);//开始菜单进入游戏
	system("pause");
	return 0;
}