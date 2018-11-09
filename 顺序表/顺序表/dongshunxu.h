#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#ifndef __DONGSHUNXU_H__
#define __DONGSHUNXU_H__

typedef int DataType;
typedef struct SeqListD
{
	DataType* _array;
	size_t _capacity;//�ײ�ռ�Ĵ�С
	size_t _size;
}SeqListD,*pSeqListD;

void SeqListDInit(pSeqListD pSeq);//��ʼ��
void SeqListDPushBack(pSeqListD pSeq,DataType x);//β��
int CheckCapacity(pSeqListD pSeq);//�������
void SeqListDPopBack(pSeqListD pSeq);//βɾ
void SeqListDDestroy(pSeqListD pSeq);//����


#endif