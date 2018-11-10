#define _CRT_SECURE_NO_WARNINGS

/*
����������
�����������ĳ�ʼ�������롢���ҡ���⡢���١�ɾ�����
�������ֲ����ĵݹ鷽��
*/

#ifndef __BSTREE_H__
#define __BSTREE_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int DataType;

typedef struct BSTreeNode
{
	DataType _data;
	struct BSTreeNode* _pLeft;
	struct BSTreeNode* _pRight;
}BSTreeNode,*pBSTreeNode;

void InitBST(pBSTreeNode* pRoot);//��ʼ��
void InsertBST(pBSTreeNode* pRoot,DataType data);//����
pBSTreeNode BuyBSTreeNode(DataType data);//�����ڵ�
int FindBSTreeNode(pBSTreeNode pRoot,DataType data);//����
void PreOrder(pBSTreeNode pRoot);//����������
void DestoryBSTree(pBSTreeNode* pRoot);//����
void DeleteBSTree(pBSTreeNode* pRoot, DataType data);//ɾ�����



int FindBSTreeNodeREC(pBSTreeNode pRoot, DataType data);//�ݹ鷽��
void InsertBSTREC(pBSTreeNode* pRoot, DataType data);//����ݹ�
void DeleteBSTreeREC(pBSTreeNode* pRoot, DataType data);//ɾ�����ݹ�




#endif