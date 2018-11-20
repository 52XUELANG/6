#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char a[10];
char ch[10] = { '#', 'E' };
char cha;
int lookahead = 0;
int length = 0;
int step = 1;
int l = 1;
int n;

void E();

void print()
{
	int i;
	printf("%d\t", step);
	for (i = 0; i <= l; i++)
	{
		printf("%c", ch[i]);
	}
	if (l < 7)
	{
		printf("\t\t");
	}
	else
	{
		printf("\t");
	}
	for (i = 0; i < lookahead; i++)
	{
		a[i] = ' ';
		printf("%c", a[i]);
	}
	for (i = lookahead; i < length; i++)
	{
		printf("%c", a[i]);
	}
	printf("\t");
}


void F()
{
	if (a[lookahead] >= 'a'&&a[lookahead]<='z')
	{
		print();
		printf("F->i\n");
		n = 0;
		l = l + n - 1;
		step++;
		lookahead++;
	}
	else if (a[lookahead] == '(')
	{
		print();
		printf("F->(E)\n");
		ch[l] = 'E';
		step++;
		lookahead++;
		E();
		if (a[lookahead] == ')')
		{
			lookahead++;
		}
		else
		{
			printf("没有')'匹配");
			system("pause");
			exit(0);
		}
	}
	else
	{
		printf("没有'('匹配\n");
		system("pause");

		exit(0);
	}
}

void T1()
{
	if (a[lookahead] == '*' || a[lookahead] == '/')
	{
		print();
		printf("T'->*FT'\n");
		n = 3;
		l = l + n - 2;
		ch[l] = 'F';
		ch[l - 1] = 39;
		ch[l - 2] = 'T';
		step++;
		lookahead++;
		F();
		T1();
	}
	//===================第二个===================
	else
	{
		print();
	}
	printf("T'->e\n");
	l = l - 2;
	step++;

}


void T()
{
	print();
	printf("T->FT'\n");
	n = 3;
	l = l + n - 1;
	ch[l] = 'F';
	ch[l - 1] = 39;
	ch[l - 2] = 'T';
	step++;
	F();
	T1();
}


void E1()
{
	if (a[lookahead] == '+' || a[lookahead] == '-')
	{
		print();
		printf("E'->+TE'\n");
		n = 3;
		l = l + n - 2;
		ch[l] = 'T';
		ch[l - 1] = 39;
		ch[l - 2] = 'E';
		step++;
		lookahead++;
		T();
		E1();
	}
	// ============================第一个===============
	else
	{
		print();
	}
	printf("E'->e\n");
	l = l - 2;
	step++;

}

void E()
{
	print();
	printf("E->TE'\n");
	n = 3;
	l = l + n - 1;
	ch[l] = 'T';
	ch[l - 1] = 39;
	ch[l - 2] = 'E';
	step++;
	T();
	E1();
}


int main()
{
	printf("输入表达式（以‘#’结束）：");
	while (a[lookahead] != '#')
	{
		do
		{
			scanf("%c", &cha);
			a[length] = cha;
			length++;
		} while (cha != '#');
		E();
		if (a[lookahead] == '#')
		{
			printf("\n The structre of the sentence is right\n");
		}
		else
		{
			printf("\n No end sign\n");
		}

	}
	system("pause");
	return 0;
}