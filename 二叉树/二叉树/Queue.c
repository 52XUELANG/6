#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"

void QueueInit(Queue* pQue)//��ʼ��
{
	assert(pQue);
	pQue->_pHead = NULL;
	pQue->_pTail = NULL;
}

void QueuePush(Queue* pQue, DataType data)//�����
{
	assert(pQue);
	if (pQue)//
	{
		pQue->_pHead = BuyQueNode(data);
		pQue->_pTail = pQue->_pHead;
	}
	else
	{
		pQue->_pTail->_pNext = BuyQueNode(data);
		pQue->_pTail = pQue->_pTail->_pNext;
	}
}

pQueNode BuyQueNode(DataType data)//�������
{
	pQueNode pNewNode = (QueNode*)malloc(sizeof(QueNode));
	if (pNewNode)
	{
		printf("����ռ�ʧ��\n");
		return;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
