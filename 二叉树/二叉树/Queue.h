#define _CRT_SECURE_NO_WARNINGS


#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef char DataType;
typedef struct Node//结构体结点
{
	DataType _data;
	struct Node* _pNext;
}QueNode,*pQueNode;

typedef struct Queue//队头队尾
{
	pQueNode _pHead;
	pQueNode _pTail;
}Queue,*pQueue;


void QueueInit(Queue* pQue);//初始化
void QueuePush(Queue* pQue, DataType data);//入队列
//出队列
//读取队头
pQueNode BuyQueNode(DataType data);//创建结点




#endif