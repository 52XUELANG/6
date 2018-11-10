#define _CRT_SECURE_NO_WARNINGS

/*
二叉搜索树
二叉搜索树的初始化、插入、查找、检测、销毁、删除结点
包含部分操作的递归方法
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

void InitBST(pBSTreeNode* pRoot);//初始化
void InsertBST(pBSTreeNode* pRoot,DataType data);//插入
pBSTreeNode BuyBSTreeNode(DataType data);//创建节点
int FindBSTreeNode(pBSTreeNode pRoot,DataType data);//查找
void PreOrder(pBSTreeNode pRoot);//中序遍历检测
void DestoryBSTree(pBSTreeNode* pRoot);//销毁
void DeleteBSTree(pBSTreeNode* pRoot, DataType data);//删除结点



int FindBSTreeNodeREC(pBSTreeNode pRoot, DataType data);//递归方法
void InsertBSTREC(pBSTreeNode* pRoot, DataType data);//插入递归
void DeleteBSTreeREC(pBSTreeNode* pRoot, DataType data);//删除结点递归




#endif