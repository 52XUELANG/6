#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"doublelist.h"

void test()
{
	pList list;
	list =  InitList();
	PushBack(list,1);
	PushBack(list, 2);
	PushBack(list, 3);
	PushBack(list, 4);
	PrintfList(list);
}

int main()
{
	test();
	system("pause");
	return 0;
}