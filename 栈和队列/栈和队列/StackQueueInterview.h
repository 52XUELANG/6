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

void MStackInit(MinStack* s);//��ʼ��
void MStackPush(MinStack* s, MSDataTtpe data);//ѹջ
void MStackPop(MinStack* s);//��ջ
#endif//��Сֵ

#if 0
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
#endif//˫ջʵ�ֶ���

#if 0

extern struct Queue;
typedef int QDataType;
typedef struct StackBy2Queue
{
	struct Queue _q1;
	struct Queue _q2;
}StackBy2Queue;

void StackBy2QueueInit(StackBy2Queue* s);
void StackBy2QueuePush(StackBy2Queue* s,QDataType data);
void StackBy2QueuePop(StackBy2Queue* s);
QDataType StackBy2QueueTop(StackBy2Queue* s);
int StackBy2QueueSize(StackBy2Queue* s);
int StackBy2QueueEmpty(StackBy2Queue* s);
#endif//˫����ʵ��ջ

//int IsValidStack(int *In,int InSize,int* Out, int OutSize);//��ջƥ��


typedef struct SharedStack
{
	int _array[100];
	int _top1;
	int _top2;
}SharedStack;


void SharedStackInit(SharedStack* psta);//��ʼ��
void SharedStackPushBack(SharedStack* psta, int num, int which);//��ջ
void SharedStackPopBack(SharedStack* psta, int which);//��ջ
int SharedStackTop(SharedStack* s, int which);//ȡ��Ԫ��
int SharedStackEmpty(SharedStack* s, int which)//�п�
int SharedStackSize(SharedStack* s, int which);//��С

#endif