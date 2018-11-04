#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include<assert.h>
#include<string.h>

void test2(pList plist)
{
	TestPrintTailToHead(plist);
	printf("\n");
	pNode pos = NULL;
	pos = Find(plist, 4);
	EraseNotTail(pos); //删除无头单链表的非尾结点
	PrintList(plist);//打印
	pos = Find(plist, 5);
	InsertNode(pos,6);//无头结点之前插入一个结点
	PrintList(plist);//打印
	//for (int i = 1; i < 10; i++)
	//{
	//	PushBack(&plist, i);
	//}
	//Find(plist,9)->next=plist;
	//JosephusCycle(&plist,3);//约瑟夫环
	ReverseList(&plist);//反转单链表
	PrintList(plist);//打印
	BubbleSort(plist);//链表冒泡排序
	PrintList(plist);//打印
	Node* plist2 = NULL;
	PushBack(&plist2, 3); 
	PushBack(&plist2, 4);
	PushBack(&plist2, 7);
	//pList plist3 = NULL;
	//plist3 = pLinkNodeMerge(plist, plist2);//合并两个有序链表（无递归）
	//PrintList(plist3);//打印
	pList plist4 = NULL;
	plist4 = pLinkNodeMerge_r(plist, plist2);//合并两个有序链表（有递归）
	PrintList(plist4);//打印
	pNode pos2 = NULL;
	pos2 = pLinkFindMidNode(plist4);//遍历一遍找到中间结点
	printf("%d\n", pos2->data);
	int k = 0;
	scanf("%d",&k);
	pNode pos5 = NULL;
	pos5 = pLinkFindLastKNode(plist4, k);//遍历一次找倒数第k个结点
	if (pos5 != NULL)
	{
		printf("%d\n", pos5->data);
	}
	Find(plist4, 7)->next = Find(plist4, 4);
	pNode pos3 =  IsCircle(plist4);//判断是否带环
	if (pos3 == NULL)
	{
		printf("不带环\n");
	}
	else
	{
		printf("带环,相遇点为%d\n",pos3->data);
	}
	int len = GetCircleLength(pos3);//求环长度
	printf("%d\n",len);

	pNode pos7 = getCircleDoor(plist4, pos3);

	printf("入口为%d\n",pos7->data);



	Node* plist5 = NULL;
	PushBack(&plist5, 1);//尾插存入数据
	PushBack(&plist5, 2);
	PushBack(&plist5, 3);
	PushBack(&plist5, 4);
	PushBack(&plist5, 5);
	PushBack(&plist5, 6);
	PushBack(&plist5, 7);
	Node* plist6 = NULL;
	PushBack(&plist6, 8);//尾插存入数据
	PushBack(&plist6, 9);
	PushBack(&plist6, 10);
	PushBack(&plist6, 11);
	PushBack(&plist6, 12);
	PushBack(&plist6, 13);
	PushBack(&plist6, 14);
	Find(plist6, 14)->next = Find(plist5, 5);
	int ans = CheckCross(plist5,plist6);
	if (ans)
	{
		printf("香蕉\n");
		pNode pos = GetCrossNode(plist5, plist6);//求香蕉点
		printf("蕉点值为%d\n",pos->data);
	}
	else
	{
		printf("不香蕉\n");
	}
	PrintList(plist5);//打印
	PrintList(plist6);//打印


	Node* plist7 = NULL;
	PushBack(&plist7, 1);//尾插存入数据
	PushBack(&plist7, 2);
	PushBack(&plist7, 3);
	PushBack(&plist7, 4);
	PushBack(&plist7, 5);
	PushBack(&plist7, 6);
	PushBack(&plist7, 7);
	Node* plist8 = NULL;
	PushBack(&plist8, 3);//尾插存入数据
	PushBack(&plist8, 4);
	PushBack(&plist8, 5);
	PushBack(&plist8, 7);
	PushBack(&plist8, 8);
	PushBack(&plist8, 9);
	PushBack(&plist8, 10);
	TestUnionSet(plist7, plist8);//有序链表求交集


	ComplexNode* plist9 = NULL;

	TestComplexCopyList(plist9);//复杂链表
}

void test()
{
	Node* plist = NULL;//定义结构体指针类型,若定义时初始化为NULL，可以不用再初始化
	//InitList(&plist);//初始化链表
	PushBack(&plist,1);//尾插存入数据
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);
	PrintList(plist);//打印
	printf("%d\n", GetListLength(plist));//查长度
	PopBack(&plist);//尾部删除
	PrintList(plist);//打印
	PushFront(&plist,5);//头插
	PrintList(plist);//打印
	PopFront(&plist);//头删
	PrintList(plist);//打印
	pNode pos = NULL;
	pos = Find(plist,3);//查找
	printf("%d\n",pos->data);
	Insert(&plist,pos,5);//指定位置插入
	PrintList(plist);//打印
	Erase(&plist,pos);//指定位置删除
	PrintList(plist);//打印
	Remove(&plist, 5);//指定元素删除
	PrintList(plist);//打印
	PushFront(&plist, 6);//头插
	PushFront(&plist, 6);//头插
	PushFront(&plist, 6);//头插
	PushBack(&plist, 6);
	PushBack(&plist, 6);
	PrintList(plist);//打印
	RemoveAll(&plist, 6);//删除指定所有元素
	PrintList(plist);//打印
	test2(plist);
	//DestroyList(&plist);//销毁链表
}



int main()
{
	
	test();
	system("pause");
	return 0;
}