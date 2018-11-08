#define _CRT_SECURE_NO_WARNINGS

#ifndef __STACKQUEUEINTERVIEW_H__
#define __STACKQUEUEINTERVIEW_H__

#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
#if 0

extern struct Stack;
typedef int MSDataTtpe;
typedef struct SElem
{
	MSDataTtpe _data;
	MSDataTtpe _min_data;
}SElem;

typedef struct MinStack
{
	struct Stack* _s;
}MinStack;

void MStackInit(MinStack* s);//³õÊ¼»¯
void MStackPush(MinStack* s, MSDataTtpe data);//Ñ¹Õ»
void MStackPop(MinStack* s);//³öÕ»
#endif

extern struct Stack;
typedef int QDataType;
typedef struct QueueBy2Stack
{
	struct Stack* _s1;
	struct Stack* _s2;
}QueueBy2Stack;
void QueueBy2StackInit(QueueBy2Stack* q);
void QueueBy2StackPush(QueueBy2Stack* q, QDataType data);
void QueueBy2StackPop(QueueBy2Stack* q);
QDataType QueueBy2StackFront(QueueBy2Stack* q);
QDataType QueueBy2StackBack(QueueBy2Stack* q);
int QueueBy2StackEmpty(QueueBy2Stack* q);




#endif