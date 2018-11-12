#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Stack.h"

//void test()
//{
//	
//	char ch[50] = { '\0' };
//	pStack psta = NULL;
//	StackInit(&psta);
//	printf("输入后缀式(#结束)：");
//	for (int i = 0; i < 50; i++)
//	{
//		scanf("%c", &ch[i]);
//		if ('#' == ch[i])
//			break;
//	}
//	for (int i = 0; i < 50; i++)
//	{
//		if (ch[i] == '+')
//		{
//			int num1 = TakeOut(psta);
//			PopBack(psta);
//			int num2 = TakeOut(psta);
//			PopBack(psta);
//			int num3 = num2 + num1;
//			PushBack(psta, num3);
//		}
//		else if (ch[i]=='-')
//		{
//			int num1 = TakeOut(psta);
//			PopBack(psta);
//			int num2 = TakeOut(psta);
//			PopBack(psta);
//			int num3 = num2 - num1;
//			PushBack(psta, num3);
//		}
//		else if (ch[i] == '*')
//		{
//			int num1 = TakeOut(psta);
//			PopBack(psta);
//			int num2 = TakeOut(psta);
//			PopBack(psta);
//			int num3 = num2 * num1;
//			PushBack(psta, num3);
//		}
//		else if (ch[i] == '/')
//		{
//			int num1 = TakeOut(psta);
//			if (num1 == 0)
//			{
//				printf("除数不能为0！\n");
//				system("pause");
//				exit(1);
//			}
//			PopBack(psta);
//			int num2 = TakeOut(psta);
//			PopBack(psta);
//			int num3 = num2 / num1;
//			PushBack(psta, num3);
//		}
//		else if (ch[i] == '#')
//		{
//			break;
//		}
//		else if (ch[i]>='0'&&ch[i]<='9')
//		{
//			PushBack(psta, atoi(&ch[i]));
//			while (ch[i]!=' ')
//			{
//				i++;
//			}
//		}
//	}
//	printf("%d\n",psta->next->data);
//}

int main()
{
	////test();
	//QueueBy2Stack q;
	//QueueBy2StackInit(&q);
	//QueueBy2StackPush(&q, 1);
	//QueueBy2StackPush(&q, 2);
	//QueueBy2StackPush(&q, 3);
	//QueueBy2StackPush(&q, 4);
	//QueueBy2StackPush(&q, 5);
	//printf("front = %d",QueueBy2StackFront(&q));
	//printf("back = %d", QueueBy2StackBack(&q));

	//QueueBy2StackPop(&q);
	//QueueBy2StackPop(&q);
	//printf("front = %d", QueueBy2StackFront(&q));
	//printf("back = %d", QueueBy2StackBack(&q));
	//StackBy2Queue s;
	//StackBy2QueueInit(&s);
	int In[] = { 1, 2, 3, 4, 5 };
	int Out[] = { 4,5, 3, 1,2 };
	if (IsValidStack(In, sizeof(In) / sizeof(In[0]), Out, sizeof(Out) / sizeof(Out[0])))
	{
		printf("匹配\n");
	}
	else
	{
		printf("NO匹配\n");

	}
	system("pause");
	return 0;
}
