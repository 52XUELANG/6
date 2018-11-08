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

pStack BuyNode(DataType num);//创建结点
void StackInit(pStack* psta);//初始化
void PushBack(pStack* psta,DataType num);//入栈
void PopBack(pStack* psta);//出栈
int TakeOut(pStack* psta);//取出元素
int StackEmpty(pStack s);//判空


#endif