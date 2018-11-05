#define _CRT_SECURE_NO_WARNINGS


/*
����������ϰ
�����ļ����ƣ�BinTree.h��BinTree.c
�������������������������ֱ������ݹ�ͷǵݹ飩�����������٣���������
���������������������񣬽������Ҷ�ӽڵ�����ͳ�ƣ��������
*/


#ifndef __BINTREE_H__
#define __BINTREE_H__
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>


typedef char BinTreeDataType;
typedef struct BinTreeNode//��ͨ������
{
	struct BinTreeNode* _pLeft;//����
	struct BinTreeNode* _pRight;//�Һ���
	BinTreeDataType _data;//����
}BinTreeNode,*pBinTreeNode;



typedef enum PointFlag //������������ö������
{
	LINK,THREAD
}PointFlag;
typedef char BinTreeThreadType;
typedef struct BinTreeThreadNode//������������
{
	struct BinTreeThreadNode* _pLeft;
	struct BinTreeThreadNode* _pRight;
	BinTreeDataType _data;
	PointFlag _LeftThread;//������
	PointFlag _RightThread;//������
}BinTreeThreadNode,*pBinTreeThreadNode;




pBinTreeNode BuyBinTreeBinTreeNode(BinTreeDataType data);//�������
void CreateBinTree(pBinTreeNode* pRoot, BinTreeDataType array[], int size, int* index/*����*/, BinTreeDataType invalid/*��Чֵ*/);//����������
void TestBinTree();//����
pBinTreeNode CopyBinTree(pBinTreeNode pRoot);//����
void PreOrder(pBinTreeNode pRoot);//ǰ��
void InOrder(pBinTreeNode pRoot);//����
void PostOrder(pBinTreeNode pRoot);//����
void DetoryBinTree(pBinTreeNode* pRoot);//����
void LevelOrder(pBinTreeNode pRoot);//�������
void MirrorBinTree(pBinTreeNode pRoot);//����
int BinTreeSize(pBinTreeNode pRoot);//������
int BinTreeLeafSize(pBinTreeNode pRoot);//Ҷ�ӽ�����
int BinTreeLevelKSize(pBinTreeNode pRoot, int k);//��k��Ľ����
pBinTreeNode BinTreeFind(pBinTreeNode pRoot, BinTreeDataType thing);//����
int BinTreeHeight(pBinTreeNode pRoot);//���߶�




#endif