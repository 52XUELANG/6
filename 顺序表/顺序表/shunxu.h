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

void SeqListInit(SeqList* pSeq);//��ʼ��
void SeqListPushBack(SeqList* pSeq, DataType x);//β��
void SeqListPushFront(SeqList* pSeq, DataType x);//ͷ��
void SeqListPopBack(SeqList* pSeq);//βɾ��
void SeqListPopFront(SeqList* pSeq);//ͷɾ��
void SeqListPrint(SeqList* pSeq);//��ӡ
void SeqListInsert(SeqList* pSeq,size_t pos,DataType x);//���λ�ò���
void SeqListErase(SeqList* pSeq, size_t pos);//���λ��ɾ��
int SeqListFind(SeqList* pSeq, DataType x);//����
void SeqListModify(SeqList* pSeq,size_t pos, DataType x);//�޸�
void SeqListRemove(SeqList* pSeq, DataType x);//ɾ������ָ��Ԫ��
void SeqListRemoveAll(SeqList* pSeq, DataType x);//ɾ������ָ��Ԫ��
void SeqListBubble(SeqList* pSeq);//ð������
void SeqListSelectSort(SeqList* pSeq);//ѡ������
void SeqListBinarySearch(SeqList* pSeq,DataType x);//���ֲ���


#endif