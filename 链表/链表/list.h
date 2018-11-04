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

pNode BuyNode(int d);//�������

void PushBack(pList* pplist, int d);//β���

void PrintList(pList plist);//��ӡ

void DestroyList(pList* pplist);//����

int GetListLength(pList plist);//��������

void PopBack(pList* pplist);//β��ɾ��

void PushFront(pList* pplist,int d);//ͷ��

void PopFront(pList* pplist);//ͷɾ

pNode Find(pList plist, int d);//����

void Insert(pList* pplist, pNode pos, int d);//ָ��λ�ò���

void Erase(pList* pplist, pNode pos);//ָ��λ��ɾ��

void Remove(pList* pplist, int d);//ָ��Ԫ�ص�һ�����ֵ�ɾ��

void RemoveAll(pList* pplist, int d);//ɾ��ָ������Ԫ��

void TestPrintTailToHead(pList plist);//�����ӡ

void EraseNotTail(pNode pos);//ɾ����ͷ������ķ�β���

void InsertNode(pNode pos,int d);//��ͷ���֮ǰ����һ�����

void JosephusCycle(pList* pplist,int k);//Լɪ��

void ReverseList(pList* pplist);//��ת������

void BubbleSort(pList plist);//����ð������

pList pLinkNodeMerge(pList plist, pList plist2);//�ϲ��������������޵ݹ飩

pList pLinkNodeMerge_r(pList plist, pList plist2);//�ϲ��������������еݹ飩

pNode pLinkFindMidNode(pList plist4);//����һ���ҵ��м���

pNode pLinkFindLastKNode(pList plist4,int k);//����һ���ҵ�����k�����

pNode IsCircle(pList plist4);//�ж��Ƿ����

int GetCircleLength(pNode pos3);//�󻷳���

pNode getCircleDoor(pList list,pNode meet);//�󻷵����

int CheckCross(pList plist1,pList plist2);//���������Ƿ��㽶

pNode GetCrossNode(pList plist5,pList plist6);//���㽶��

void TestUnionSet(pList plist1, pList plist2);//�󽻼�


typedef struct ComplexNode
{
	int data;
	struct  ComplexNode* next;
	struct  ComplexNode* random;
}ComplexNode;//��������Ľṹ��

ComplexNode* BuyComplexNode(int d);//������������Ľ��

void TestComplexCopyList(ComplexNode* plist);//��������

void PrintfComplexList(ComplexNode* plist);//��ӡ��������

ComplexNode* CopyComplexList(ComplexNode* plist);//��������

#endif