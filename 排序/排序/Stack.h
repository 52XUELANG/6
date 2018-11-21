#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#ifndef __STACK_H__
#define __STACK_H__

typedef int DataType;

typedef struct Stack
{
	DataType data;
	int size;
	struct Stack* next;
} Stack,*pStack;

pStack BuyNode(DataType num);//�������
void StackInit(pStack* psta);//��ʼ��
void PushBack(pStack* psta,DataType num);//��ջ
void PopBack(pStack* psta);//��ջ
int TakeOut(psta);//ȡ��Ԫ��
int StackEmpty(pStack s);//�п�

#endif