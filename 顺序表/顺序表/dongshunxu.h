#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#ifndef __DONGSHUNXU_H__
#define __DONGSHUNXU_H__

typedef int DataType;
typedef struct SeqListD
{
	DataType* _array;
	size_t _capacity;//底层空间的大小
	size_t _size;
}SeqListD,*pSeqListD;

void SeqListDInit(pSeqListD pSeq);//初始化
void SeqListDPushBack(pSeqListD pSeq,DataType x);//尾插
int CheckCapacity(pSeqListD pSeq);//检查容量
void SeqListDPopBack(pSeqListD pSeq);//尾删
void SeqListDDestroy(pSeqListD pSeq);//销毁


#endif