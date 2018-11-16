#define _CRT_SECURE_NO_WARNINGS
#include"HashBucket.h"
#include"common.h"

void HashBucketInit(pHashBucket ht, int capacity, PElemToInt pElemToInt)//��ʼ��
{
	assert(ht);
	capacity =2/* GetNextPrime(capacity)*/;
	ht->_table = (HashNode**)malloc(sizeof(HashNode*)*capacity);
	if (ht->_table == NULL)
	{
		assert(0);
		return;
	}
	ht->_capacity = capacity;
	for (int i = 0; i < ht->_capacity; i++)
	{
		ht->_table[i] = NULL;
	}
	
	ht->_size = 0;
	ht->_pElemToInt = pElemToInt;
}
void HashBuctetInsertUnique(pHashBucket ht, HNDataType data)//���벻���ظ���Ԫ��
{
	if (0 == HashBucketCheckCapacity(ht))
	{
		return;
	}
	int BucketNo = HashBucketFunc(ht,data);//�ҵ�λ��
	//���Ԫ���Ƿ����
	HashNode* pCur = NULL;
	pCur =	ht->_table[BucketNo];
	while (pCur)
	{
		if (data == pCur->_data)
			return;
		pCur = pCur->_pNext;
	}

	//ͷ��
	HashNode* pNewNode = BuyHashNode(data);
	pNewNode->_pNext = ht->_table[BucketNo];
	ht->_table[BucketNo] = pNewNode;
	ht->_size++;
}
void HashDeleteUnique(pHashBucket ht, HNDataType data)//ɾ�����ظ���Ԫ��
{
	int BucketNo = HashBucketFunc(ht, data);//ɾ��λ��

	//���Ԫ���Ƿ����
	HashNode* pPre = NULL;
	HashNode* pCur = ht->_table[BucketNo];
	while (pCur)
	{
		if (data == pCur->_data)
		{
			if (pCur == ht->_table[BucketNo])//�����еĵ�һ���ڵ�
			{
				ht->_table[BucketNo] = pCur->_pNext;
			}
			else//���ǵ�һ���ڵ�
			{
				pPre->_pNext = pCur->_pNext;
			}
			free(pCur);
			ht->_size--;
			return;
		}
		pPre = pCur;
		pCur = pCur->_pNext;
	}
}
void HashBucketInsertEqual(pHashBucket ht, HNDataType data)//������ظ���Ԫ��
{
	if (0 == HashBucketCheckCapacity(ht))
	{
		return;
	}
	int BucketNo = HashBucketFunc(ht, data);//�ҵ�λ��
	//ͷ��
	HashNode* pNewNode = BuyHashNode(data);
	pNewNode->_pNext = ht->_table[BucketNo];
	ht->_table[BucketNo] = pNewNode;
	ht->_size++;
}
void HashDeleteEqual(pHashBucket ht, HNDataType data)//ɾ���ظ���Ԫ��
{
	int BucketNo = HashBucketFunc(ht, data);//ɾ��λ��
	HashNode* pPre = NULL;
	HashNode* pCur = ht->_table[BucketNo];
	while (pCur)
	{
		if (data == pCur->_data)
		{
			if (pCur == ht->_table[BucketNo])
			{
				ht->_table[BucketNo] = pCur->_pNext;
				free(pCur);
				pCur = ht->_table[BucketNo];
			}
			else
			{
				pPre->_pNext = pCur->_pNext;
				free(pCur);
				pCur = pPre->_pNext;
			}
		}
		else
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
	}
	return;
}
//pHashNode HashBucketFind(pHashBucket ht, HNDataType data)//����
//{
//
//}
int HashBucketSize(pHashBucket ht)//��С
{
	return ht->_size;
}
int HashBucketEmpty(pHashBucket ht)//�п�
{
	return 0 == ht->_size;
}
int HashBucketDestroy(pHashBucket ht)//���ٹ�ϣ��
{
	for (int i = 0; i < ht->_capacity; i++)
	{
		HashNode* pCur = ht->_table[i];
		while (pCur)
		{
			ht->_table[i] = pCur->_pNext;
			free(pCur);
			pCur = ht->_table[i];
		}
	}
	free(ht->_table);
	ht->_capacity = 0;
	ht->_size = 0;
	return 1;
}
int HashBucketFunc(pHashBucket ht, HNDataType data)//��ϣ����
{
	return ht->_pElemToInt(data) % ht->_capacity;
}
pHashNode BuyHashNode(HNDataType data)//�������
{
	HashNode* pNewNode = (HashNode*)malloc(sizeof(HashNode));
	if (pNewNode == NULL)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_pNext = NULL;
	pNewNode->_data = data;
	return pNewNode;
}
int HashBucketCheckCapacity(pHashBucket ht)//����
{
	assert(ht);
	if (ht->_capacity == ht->_size)
	{
		size_t newCpacity = GetNextPrime(ht->_capacity);
		HashNode** pNewTable = (HashNode**)malloc(newCpacity*sizeof(HashNode*));
		if (pNewTable == NULL)
		{
			assert(0);
			return 0;
		}

		for (size_t i = 0; i < newCpacity; i++)//���¿ռ��ʼ��
		{
			pNewTable[i] = NULL;
		}

		//����Ԫ��
		for (int i = 0; i < ht->_capacity; i++)
		{
			HashNode* pCur = ht->_table[i];
			int bucketNo = -1;
			while (pCur)
			{
				ht->_table[i] = pCur->_pNext;//��Ͱ��i��Ͱ�ĵ�һ���ڵ�
				bucketNo = ht->_pElemToInt(pCur->_data) % newCpacity;//��Ͱ��Ͱ��
				pCur->_pNext = pNewTable[bucketNo];
				pNewTable[bucketNo] = pCur;//ͷ��
				pCur = ht->_table[i];//��ԭͰ����һ�����
			}
		}
		free(ht->_table);
		ht->_table = pNewTable;
		ht->_capacity = newCpacity;
	}
	return 1;
}
