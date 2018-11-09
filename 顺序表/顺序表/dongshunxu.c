#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"dongshunxu.h"
#include<assert.h>

void SeqListDInit(pSeqListD pSeq)//初始化
{
	if (pSeq == NULL)
	{
		return;
	}
	//pSeq->_array = NULL;
	//pSeq->_capacity = 0;
	//pSeq->_size = 0;//第一,不给予空间


	pSeq->_array = (DataType*)malloc(5*sizeof(DataType));//给予默认的大小的空间
	if (NULL==pSeq->_array)
	{
		return;
	}
	pSeq->_capacity = 3;
	pSeq->_size = 0;
}

int CheckCapacity(pSeqListD pSeq)//检查容量
{
	if (pSeq->_size == pSeq->_capacity)
	{
		//扩容
		size_t newCapacity = pSeq->_capacity * 2;
		DataType* pTemp = (DataType*)malloc(sizeof(DataType)*newCapacity);//扩大二倍
		if (NULL == pTemp)
		{
			return 0;
		}
		//搬移元素
		memcpy(pTemp, pSeq->_array, sizeof(int)*pSeq->_size);
		free(pSeq->_array);
		pSeq->_array = pTemp;
		pSeq->_capacity = newCapacity;
	}
}

void SeqListDPushBack(pSeqListD pSeq, DataType x)//尾插
{
	if (pSeq->_size == pSeq->_capacity)
	{
		CheckCapacity(pSeq);
	}
	pSeq->_array[pSeq->_size] = x;
	pSeq->_size++;
}

void SeqListDPopBack(pSeqListD pSeq)//尾删
{
	assert(pSeq);
	if (pSeq==NULL)
	{
		return;
	}
	pSeq->_size--;
}

void SeqListDDestroy(pSeqListD pSeq)//销毁
{
	if (pSeq->_array)
	{
		free(pSeq->_array);
		pSeq->_capacity = 0;
		pSeq->_size = 0;
	}
}