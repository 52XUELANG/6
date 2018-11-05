#define _CRT_SECURE_NO_WARNINGS


/*
二叉树的练习
包含文件名称：BinTree.h，BinTree.c
二叉树基本操作：建立，三种遍历（递归和非递归），拷贝，销毁，附带测试
二叉树的其他操作：镜像，结点数和叶子节点数的统计，层序遍历
*/


#ifndef __BINTREE_H__
#define __BINTREE_H__
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>


typedef char BinTreeDataType;
typedef struct BinTreeNode//普通二叉树
{
	struct BinTreeNode* _pLeft;//左孩子
	struct BinTreeNode* _pRight;//右孩子
	BinTreeDataType _data;//数据
}BinTreeNode,*pBinTreeNode;



typedef enum PointFlag //线索化二叉树枚举线索
{
	LINK,THREAD
}PointFlag;
typedef char BinTreeThreadType;
typedef struct BinTreeThreadNode//线索化二叉树
{
	struct BinTreeThreadNode* _pLeft;
	struct BinTreeThreadNode* _pRight;
	BinTreeDataType _data;
	PointFlag _LeftThread;//左线索
	PointFlag _RightThread;//右线索
}BinTreeThreadNode,*pBinTreeThreadNode;




pBinTreeNode BuyBinTreeBinTreeNode(BinTreeDataType data);//创建结点
void CreateBinTree(pBinTreeNode* pRoot, BinTreeDataType array[], int size, int* index/*索引*/, BinTreeDataType invalid/*无效值*/);//创建二叉树
void TestBinTree();//测试
pBinTreeNode CopyBinTree(pBinTreeNode pRoot);//拷贝
void PreOrder(pBinTreeNode pRoot);//前序
void InOrder(pBinTreeNode pRoot);//中序
void PostOrder(pBinTreeNode pRoot);//后序
void DetoryBinTree(pBinTreeNode* pRoot);//销毁
void LevelOrder(pBinTreeNode pRoot);//层序遍历
void MirrorBinTree(pBinTreeNode pRoot);//镜像
int BinTreeSize(pBinTreeNode pRoot);//结点个数
int BinTreeLeafSize(pBinTreeNode pRoot);//叶子结点个数
int BinTreeLevelKSize(pBinTreeNode pRoot, int k);//第k层的结点数
pBinTreeNode BinTreeFind(pBinTreeNode pRoot, BinTreeDataType thing);//查找
int BinTreeHeight(pBinTreeNode pRoot);//树高度




#endif