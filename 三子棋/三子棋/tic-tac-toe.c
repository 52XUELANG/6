#define _CRT_SECURE_NO_WARNINGS
#include"game.h"




int main()
{
	int check[3][3] = {0};//���岢��ʼ�������̡�
	srand((unsigned int)time(NULL));//����ʱ����������
	Menu(check);//��ʼ�˵�������Ϸ
	system("pause");
	return 0;
}