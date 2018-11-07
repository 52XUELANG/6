#define _CRT_SECURE_NO_WARNINGS
#ifndef __HEAP_H__
#define __HEAP_H__

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;
typedef int(*Compare) (DataType data1, DataType data2);//函数指针
typedef struct Heap
{
	DataType* _array;//动态数组
	int _capacity;//容量
	int _size;//大小
	Compare com;
}Heap,*pHeap;


typedef struct PriorityQueue//优先级队列
{
	Heap _hp;
}PQueue,*pPQueue;



void CreateHeap(Heap* hp,DataType* array,int size, Compare com);//创建堆
void InitHeap(Heap* hp, int size);//初始化
void AdjustDown(Heap* hp,int root,Compare com);//向下调整
void Swap(DataType* pData1,DataType* pData2);//交换
void InsertHeap(Heap* hp,DataType data, Compare com);//插入
void CheckCapacity(Heap* hp);//检测容量
void AdjustUp(Heap* hp, int child,int parent,Compare com);//向上调整
void DeleteHeap(Heap* hp, Compare com);//删除
int EmptyHeap(Heap* hp);//判空
int Less(DataType data1, DataType data2);//小
int Bigger(DataType data1, DataType data2);//大
DataType TopHead(Heap* hp);//获取堆顶元素




void InitPQueue(PQueue* Pq);//优先级队列初始化
void PushPQueue(PQueue* Pq, DataType data, Compare com);//插入
void PopPQueue(PQueue* Pq,Compare com);//出队列
int SizePQueue(PQueue* Pq);//查询大小
int EmptyPQueue(PQueue* Pq);//判空
DataType TopPQueue(PQueue* Pq);






void HeapSort(Heap* hp, Compare com);//堆排序

#endif