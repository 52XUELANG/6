#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"doublelist.h"

pDnode BuyNode(int d)
{
	pDnode ptr = (pDnode)malloc(sizeof(Dnode));
	if (ptr == NULL)
	{
		perror("Buy::malloc");
		return NULL;
	}
	ptr->data = d;
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}

pList InitList()//³õÊ¼»¯
{
	pDnode plist =  BuyNode(0);
	plist->next = plist;
	plist->prev = plist;
	return plist;
}

void PushBack(pDnode list,int d)//Î²²å
{
	pDnode head = list;
	pDnode tail = list->prev;
	pDnode newNode = BuyNode(d);
	tail->next = newNode;
	newNode->prev = tail;
	head->prev = newNode;
	newNode->next = head;
}

void PrintfList(pDnode list)//´òÓ¡
{
	pDnode cur = list->next;
	while (cur != list)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("head\n");
}
