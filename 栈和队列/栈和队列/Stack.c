#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Stack.h"

pStack BuyNode(DataType num)//�������
{
	pStack newNode = (Stack*)malloc(sizeof(Stack));
	if (NULL == newNode)
	{
		printf("�ռ�����ʧ��\n");
		assert(0);
		return NULL;
	}
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}


void StackInit(pStack* psta)//��ʼ��
{
	assert(psta);
	*psta = BuyNode(0);
}


void PushBack(pStack* psta, DataType num)//��ջ
{
	pStack cur = *psta;
	while (NULL!=cur->next)
	{
		cur = cur->next;
	}
	pStack newNode = BuyNode(num);
	cur->next = newNode;
}


void PopBack(pStack* psta)//��ջ
{
	pStack cur = *psta;
	while (NULL!=cur->next->next)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

int TakeOut(pStack* psta)//ȡ��Ԫ��
{
	pStack cur = *psta;
	while (NULL !=  cur->next)
	{
		cur = cur->next;
	}
	return cur->data;
}

int StackEmpty(pStack s)//�п�
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
