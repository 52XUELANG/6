#define _CRT_SECURE_NO_WARNINGS
#include"game.h"


void Initialization(int check[3][3])//��ʼ�����̲���ӡ
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

	printf("���̳�ʼ�����\n");
}

void PrintingCheckerboard(int check[3][3])//��ӡˢ������
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

int JudgeWinAndLose(int check[3][3])//�ж���Ӯ���ж�ʤ������ֵΪ1��û��ʤ��Ϊ0
{
	for (int line = 0; line < 3; line++)//�����ж�
	{

		if (   check[line][0] == check[line][1] 
			&& check[line][1] == check[line][2] 
			&& check[line][0] == check[line][2] 
			&& check[line][0] != '_')
		{
			printf("ʤ��\n");
			printf("��Ϸ����\n");
			return 1;
		}
	}


	for (int column = 0; column < 3; column++)//�����ж�
	{
		if (   check[0][column] == check[1][column] 
			&& check[1][column] == check[2][column] 
			&& check[0][column] == check[2][column] 
			&& check[0][column] != '_' )
		{
			printf("ʤ��\n");
			printf("��Ϸ����\n");
			return 1;
		}
	}


	if (check[0][0] == check[1][1] 
		&& check[1][1] == check[2][2] 
		&& check[0][0] == check[2][2] 
		&& check[1][1] != '_' 
		&& check[0][0] != '_' 
		&& check[2][2] != '_')//��б���ж�
	{
		printf("ʤ��\n");
		printf("��Ϸ����\n");
		return 1;
	}


	if (check[0][2] == check[1][1] 
		&& check[1][1] == check[2][0] 
		&& check[0][2] == check[2][0] 
		&& check[1][1] != '_' 
		&& check[0][2] != '_' 
		&& check[2][0] != '_')//б���ж�
	{
		printf("ʤ��\n");
		printf("��Ϸ����\n");
		return 1;
	}


	return 0;
}

void Player1(int check[3][3])//һ�����
{
	int line = 0;
	int column = 0;//�������й��������


	while (1)
	{
		printf("һ��������������(��������3����)��");
		scanf("%d %d", &line, &column);


		if (line > 3 || column > 3)//����������
		{
			printf("�밴�����������꣡\n");
			continue;
		}


		line = line - 1;
		column = column - 1; //����ֵ - 1��Ӧ�����±�


		if (check[line][column] == '_')
		{
			check[line][column] = '*';
			break;
		}
		else
		{
			printf("�������������ӣ�");
			continue;
		}
	}


	PrintingCheckerboard(check);//��ӡ����
}

void Player2(int check[3][3])//�������
{
	int line = 0;
	int column = 0;


	while (1)
	{
		printf("����������������(��������3����)��");
		scanf("%d %d", &line, &column);

		if (line > 3 || column > 3)//����������
		{
			printf("�밴�����������꣡\n");
			continue;
		}

		line = line - 1;
		column = column - 1;//����ֵ-1��Ӧ�����±�

		if (check[line][column] == '_')
		{
			check[line][column] = '%';
			break;
		}
		else
		{
			printf("�������������ӣ�");
			continue;
		}
	}


	PrintingCheckerboard(check);//��ӡ����
}

void Computer(int check[3][3])//�������
{
	int line = 0;
	int column = 0;//�������д�������
	printf("�����ߣ�\n");

	while (1)
	{
		line = rand() % 3;
		column = rand() % 3;//�������������
		if (check[line][column] == '_')
		{
			check[line][column] = 'X';
			PrintingCheckerboard(check);//��ӡ����
			break;
		}
	}

}

int Full(int check[3][3])//������Ա�ж�
{
	int count = 0;

	for (int line = 0; line < 3; line++)
	{

		for (int column = 0; column < 3; column++)
		{
			if (check[line][column] != '_')//�Էǡ�_�����ż�������9����������
			{
				count++;
			}
		}

	}

	if (count == 9)//����������ֵΪ1������Ϊ0
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void Game(int check[3][3],int ret)//��Ϸ����
{
	if (ret==0)//���˫�˶�ս
	{
		Initialization(check);//��ʼ������

		while (1)
		{
			Player1(check);//һ�����
			int x1 = JudgeWinAndLose(check);//��Ӯ����ֵ��Ϊ1�ж�ʤ��������ѭ��
			if (x1)
			{
				break;
			}

			int x2 = Full(check);//�����̷���ֵ��������ֵΪ1����Ϸ����������ѭ��

			if (x2 == 1)
			{
				printf("��������\n");
				printf("��Ϸ����\n");
				break;
			}

			Player2(check);//�������
			int y1 = JudgeWinAndLose(check);//��Ӯ����ֵ��Ϊ1�ж�ʤ��������ѭ��
			if (y1)
			{
				break;
			}

			int y2 = Full(check);//�����̷���ֵ��������ֵΪ1����Ϸ����������ѭ��
			if (y2 == 1)
			{
				printf("��������\n");
				printf("��Ϸ����\n");
				break;
			}
		}//ѭ������
	}

	else//����Զ�ս
	{
		Initialization(check);//��ʼ������
		while (1)
		{
			Player1(check);//һ�����
			int x1 = JudgeWinAndLose(check);//��Ӯ����ֵ
			if (x1== 1)
			{
				break;
			}

			int x2 = Full(check);//�����̷���ֵ
			if (x2 == 1)
			{
				printf("��������\n");
				printf("��Ϸ����\n");
				break;
			}

			Computer(check);//�������
			int y1 = JudgeWinAndLose(check);//��Ӯ����ֵ
			if (y1 == 1)
			{
				break;
			}

			int y2 = Full(check);//�����̷���ֵ
			if (y2 == 1)
			{
				printf("��������\n");
				printf("��Ϸ����\n");
				break;
			}
		}//ѭ�������
	}
	
}

int SelectionMenu()//ѡ��˵�
{
	while (1)
	{
		int selection = 0;
		printf("ѡ������Զ�ս������Ҷ�ս��\n��ң�0\t���ԣ�1\n");
		scanf("%d",&selection);//����ѡ����Ϸ��ʽ

		if (selection == 1)
		{
			printf("����Զ�ս\n");
			return 1;
		}
		else

		if (selection == 0)
		{
			printf("����Ҷ�ս\n");
			return 0;
		}
		else
		{
			printf("������涨���֣�");
			continue;
		}
	}

}

void Menu(int check[3][3]) //��ʼ�˵�
{
	while (1)
	{
		char play = '\0';
		printf("�Ƿ�ʼ���ǣ�y��,���������룩\n");
		play = getchar();

		if (play == 'y')//�ж��Ƿ�ʼ
		{
			int ret = 0;
			ret = SelectionMenu();//ѡ����Ϸ��ʽ
			Game(check,ret);//��Ϸ
		}
		else
		{
			printf("��Ϸ����\n");
		}

		while (getchar() != '\n')
		{
			fflush(stdin);//��ջس���
		}

		char again = '\0';
		printf("�Ƿ����¿�ʼ���ǣ�y��,���������룩\n");//���¿�ʼѡ��
		again = getchar();

		if (again == 'y')
		{
			while (getchar() != '\n')
			{
				fflush(stdin);//��ջس���
			}
			continue;
		}

		else
		{
			break;
		}
	}
}


