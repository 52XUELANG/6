#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#ifndef __SHUNXU_H__
#define __SHUNXU_H__

typedef int DataType;
#define N 20

typedef struct Seqlist
{
	DataType _a[ N ];
	size_t _size;

}SeqList;

void SeqListInit(SeqList* pSeq);//初始化
void SeqListPushBack(SeqList* pSeq, DataType x);//尾插
void SeqListPushFront(SeqList* pSeq, DataType x);//头插
void SeqListPopBack(SeqList* pSeq);//尾删除
void SeqListPopFront(SeqList* pSeq);//头删除
void SeqListPrint(SeqList* pSeq);//打印
void SeqListInsert(SeqList* pSeq,size_t pos,DataType x);//随机位置插入
void SeqListErase(SeqList* pSeq, size_t pos);//随机位置删除
int SeqListFind(SeqList* pSeq, DataType x);//查找
void SeqListModify(SeqList* pSeq,size_t pos, DataType x);//修改
void SeqListRemove(SeqList* pSeq, DataType x);//删除所有指定元素
void SeqListRemoveAll(SeqList* pSeq, DataType x);//删除所有指定元素
void SeqListBubble(SeqList* pSeq);//冒泡排序
void SeqListSelectSort(SeqList* pSeq);//选择排序
void SeqListBinarySearch(SeqList* pSeq,DataType x);//二分查找


#endif