#define _CRT_SECURE_NO_WARNINGS


#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef char DataType;
typedef struct Node//�ṹ����
{
	DataType _data;
	struct Node* _pNext;
}QueNode,*pQueNode;

typedef struct Queue//��ͷ��β
{
	pQueNode _pHead;
	pQueNode _pTail;
}Queue,*pQueue;


void QueueInit(Queue* pQue);//��ʼ��
void QueuePush(Queue* pQue, DataType data);//�����
//������
//��ȡ��ͷ
pQueNode BuyQueNode(DataType data);//�������




#endif