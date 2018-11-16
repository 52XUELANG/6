#define _CRT_SECURE_NO_WARNINGS
#include"HashBucket.h"
#include"common.h"

void HashBucketInit(pHashBucket ht, int capacity, PElemToInt pElemToInt)//初始化
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
void HashBuctetInsertUnique(pHashBucket ht, HNDataType data)//插入不可重复的元素
{
	if (0 == HashBucketCheckCapacity(ht))
	{
		return;
	}
	int BucketNo = HashBucketFunc(ht,data);//挂的位置
	//检测元素是否存在
	HashNode* pCur = NULL;
	pCur =	ht->_table[BucketNo];
	while (pCur)
	{
		if (data == pCur->_data)
			return;
		pCur = pCur->_pNext;
	}

	//头插
	HashNode* pNewNode = BuyHashNode(data);
	pNewNode->_pNext = ht->_table[BucketNo];
	ht->_table[BucketNo] = pNewNode;
	ht->_size++;
}
void HashDeleteUnique(pHashBucket ht, HNDataType data)//删除无重复的元素
{
	int BucketNo = HashBucketFunc(ht, data);//删的位置

	//检测元素是否存在
	HashNode* pPre = NULL;
	HashNode* pCur = ht->_table[BucketNo];
	while (pCur)
	{
		if (data == pCur->_data)
		{
			if (pCur == ht->_table[BucketNo])//链表中的第一个节点
			{
				ht->_table[BucketNo] = pCur->_pNext;
			}
			else//不是第一个节点
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
void HashBucketInsertEqual(pHashBucket ht, HNDataType data)//插入可重复的元素
{
	if (0 == HashBucketCheckCapacity(ht))
	{
		return;
	}
	int BucketNo = HashBucketFunc(ht, data);//挂的位置
	//头插
	HashNode* pNewNode = BuyHashNode(data);
	pNewNode->_pNext = ht->_table[BucketNo];
	ht->_table[BucketNo] = pNewNode;
	ht->_size++;
}
void HashDeleteEqual(pHashBucket ht, HNDataType data)//删除重复的元素
{
	int BucketNo = HashBucketFunc(ht, data);//删的位置
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
//pHashNode HashBucketFind(pHashBucket ht, HNDataType data)//查找
//{
//
//}
int HashBucketSize(pHashBucket ht)//大小
{
	return ht->_size;
}
int HashBucketEmpty(pHashBucket ht)//判空
{
	return 0 == ht->_size;
}
int HashBucketDestroy(pHashBucket ht)//销毁哈希表
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
int HashBucketFunc(pHashBucket ht, HNDataType data)//哈希函数
{
	return ht->_pElemToInt(data) % ht->_capacity;
}
pHashNode BuyHashNode(HNDataType data)//创建结点
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
int HashBucketCheckCapacity(pHashBucket ht)//增容
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

		for (size_t i = 0; i < newCpacity; i++)//对新空间初始化
		{
			pNewTable[i] = NULL;
		}

		//搬移元素
		for (int i = 0; i < ht->_capacity; i++)
		{
			HashNode* pCur = ht->_table[i];
			int bucketNo = -1;
			while (pCur)
			{
				ht->_table[i] = pCur->_pNext;//旧桶的i号桶的第一个节点
				bucketNo = ht->_pElemToInt(pCur->_data) % newCpacity;//新桶的桶号
				pCur->_pNext = pNewTable[bucketNo];
				pNewTable[bucketNo] = pCur;//头插
				pCur = ht->_table[i];//找原桶的下一个结点
			}
		}
		free(ht->_table);
		ht->_table = pNewTable;
		ht->_capacity = newCpacity;
	}
	return 1;
}
