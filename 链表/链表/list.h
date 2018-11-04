#define _CRT_SECURE_NO_WARNINGS
#ifndef __LIST_H__
#define __LIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct Node
{
	int data;
	struct Node* next;

} Node,*pNode,*pList;

//void InitList(pList* pplist);

pNode BuyNode(int d);//创建结点

void PushBack(pList* pplist, int d);//尾添加

void PrintList(pList plist);//打印

void DestroyList(pList* pplist);//销毁

int GetListLength(pList plist);//求链表长度

void PopBack(pList* pplist);//尾部删除

void PushFront(pList* pplist,int d);//头插

void PopFront(pList* pplist);//头删

pNode Find(pList plist, int d);//查找

void Insert(pList* pplist, pNode pos, int d);//指定位置插入

void Erase(pList* pplist, pNode pos);//指定位置删除

void Remove(pList* pplist, int d);//指定元素第一个出现的删除

void RemoveAll(pList* pplist, int d);//删除指定所有元素

void TestPrintTailToHead(pList plist);//逆序打印

void EraseNotTail(pNode pos);//删除无头单链表的非尾结点

void InsertNode(pNode pos,int d);//无头结点之前插入一个结点

void JosephusCycle(pList* pplist,int k);//约瑟夫环

void ReverseList(pList* pplist);//反转单链表

void BubbleSort(pList plist);//链表冒泡排序

pList pLinkNodeMerge(pList plist, pList plist2);//合并两个有序链表（无递归）

pList pLinkNodeMerge_r(pList plist, pList plist2);//合并两个有序链表（有递归）

pNode pLinkFindMidNode(pList plist4);//遍历一遍找到中间结点

pNode pLinkFindLastKNode(pList plist4,int k);//遍历一次找倒数第k个结点

pNode IsCircle(pList plist4);//判断是否带环

int GetCircleLength(pNode pos3);//求环长度

pNode getCircleDoor(pList list,pNode meet);//求环的入口

int CheckCross(pList plist1,pList plist2);//两条链表是否香蕉

pNode GetCrossNode(pList plist5,pList plist6);//求香蕉点

void TestUnionSet(pList plist1, pList plist2);//求交集


typedef struct ComplexNode
{
	int data;
	struct  ComplexNode* next;
	struct  ComplexNode* random;
}ComplexNode;//复杂链表的结构体

ComplexNode* BuyComplexNode(int d);//创建复杂链表的结点

void TestComplexCopyList(ComplexNode* plist);//复杂链表

void PrintfComplexList(ComplexNode* plist);//打印复杂链表

ComplexNode* CopyComplexList(ComplexNode* plist);//拷贝函数

#endif