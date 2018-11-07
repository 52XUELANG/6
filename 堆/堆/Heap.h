#define _CRT_SECURE_NO_WARNINGS
#ifndef __HEAP_H__
#define __HEAP_H__

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;
typedef int(*Compare) (DataType data1, DataType data2);//����ָ��
typedef struct Heap
{
	DataType* _array;//��̬����
	int _capacity;//����
	int _size;//��С
	Compare com;
}Heap,*pHeap;


typedef struct PriorityQueue//���ȼ�����
{
	Heap _hp;
}PQueue,*pPQueue;



void CreateHeap(Heap* hp,DataType* array,int size, Compare com);//������
void InitHeap(Heap* hp, int size);//��ʼ��
void AdjustDown(Heap* hp,int root,Compare com);//���µ���
void Swap(DataType* pData1,DataType* pData2);//����
void InsertHeap(Heap* hp,DataType data, Compare com);//����
void CheckCapacity(Heap* hp);//�������
void AdjustUp(Heap* hp, int child,int parent,Compare com);//���ϵ���
void DeleteHeap(Heap* hp, Compare com);//ɾ��
int EmptyHeap(Heap* hp);//�п�
int Less(DataType data1, DataType data2);//С
int Bigger(DataType data1, DataType data2);//��
DataType TopHead(Heap* hp);//��ȡ�Ѷ�Ԫ��




void InitPQueue(PQueue* Pq);//���ȼ����г�ʼ��
void PushPQueue(PQueue* Pq, DataType data, Compare com);//����
void PopPQueue(PQueue* Pq,Compare com);//������
int SizePQueue(PQueue* Pq);//��ѯ��С
int EmptyPQueue(PQueue* Pq);//�п�
DataType TopPQueue(PQueue* Pq);






void HeapSort(Heap* hp, Compare com);//������

#endif