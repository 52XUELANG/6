#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Stack.h"

pStack BuyNode(DataType num)//创建结点
{
	pStack newNode = (Stack*)malloc(sizeof(Stack));
	if (NULL == newNode)
	{
		printf("空间申请失败\n");
		assert(0);
		return NULL;
	}
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}


void StackInit(pStack* psta)//初始化
{
	assert(psta);
	*psta = BuyNode(0);
}


void PushBack(pStack* psta, DataType num)//入栈
{
	pStack cur = *psta;
	while (NULL!=cur->next)
	{
		cur = cur->next;
	}
	pStack newNode = BuyNode(num);
	cur->next = newNode;
}


void PopBack(pStack* psta)//出栈
{
	pStack cur = *psta;
	while (NULL!=cur->next->next)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

int TakeOut(pStack* psta)//取出元素
{
	pStack cur = *psta;
	while (NULL !=  cur->next)
	{
		cur = cur->next;
	}
	return cur->data;
}

int StackEmpty(pStack s)//判空
{
	assert(s);
	if (s->next)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
