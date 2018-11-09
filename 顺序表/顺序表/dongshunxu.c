#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"dongshunxu.h"
#include<assert.h>

void SeqListDInit(pSeqListD pSeq)//��ʼ��
{
	if (pSeq == NULL)
	{
		return;
	}
	//pSeq->_array = NULL;
	//pSeq->_capacity = 0;
	//pSeq->_size = 0;//��һ,������ռ�


	pSeq->_array = (DataType*)malloc(5*sizeof(DataType));//����Ĭ�ϵĴ�С�Ŀռ�
	if (NULL==pSeq->_array)
	{
		return;
	}
	pSeq->_capacity = 3;
	pSeq->_size = 0;
}

int CheckCapacity(pSeqListD pSeq)//�������
{
	if (pSeq->_size == pSeq->_capacity)
	{
		//����
		size_t newCapacity = pSeq->_capacity * 2;
		DataType* pTemp = (DataType*)malloc(sizeof(DataType)*newCapacity);//�������
		if (NULL == pTemp)
		{
			return 0;
		}
		//����Ԫ��
		memcpy(pTemp, pSeq->_array, sizeof(int)*pSeq->_size);
		free(pSeq->_array);
		pSeq->_array = pTemp;
		pSeq->_capacity = newCapacity;
	}
}

void SeqListDPushBack(pSeqListD pSeq, DataType x)//β��
{
	if (pSeq->_size == pSeq->_capacity)
	{
		CheckCapacity(pSeq);
	}
	pSeq->_array[pSeq->_size] = x;
	pSeq->_size++;
}

void SeqListDPopBack(pSeqListD pSeq)//βɾ
{
	assert(pSeq);
	if (pSeq==NULL)
	{
		return;
	}
	pSeq->_size--;
}

void SeqListDDestroy(pSeqListD pSeq)//����
{
	if (pSeq->_array)
	{
		free(pSeq->_array);
		pSeq->_capacity = 0;
		pSeq->_size = 0;
	}
}