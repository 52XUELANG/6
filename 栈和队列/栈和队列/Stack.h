#define _CRT_SECURE_NO_WARNINGS


#ifndef __STACK_H__
#define __STACK_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"StackQueueInterview.h"

typedef int DataType;
//extern struct SElem;
//typedef struct SElem DataType;

typedef struct Stack
{
	DataType data;
	struct Stack* next;
}Stack, *pStack;

pStack BuyNode(DataType num);//�������
void StackInit(pStack* psta);//��ʼ��
void PushBack(pStack* psta,DataType num);//��ջ
void PopBack(pStack* psta);//��ջ
int TakeOut(pStack* psta);//ȡ��Ԫ��
int StackEmpty(pStack s);//�п�


#endif