#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

typedef struct Dnode
{
	int data;
	struct Dnode*next;
	struct Dnode*prev;
}Dnode,*pDnode,*pList;

pList InitList();//��ʼ��
pDnode BuyNode(int d);//���ɽ��
void PushBack(pDnode list,int d);
void PrintfList(pDnode list);

#endif