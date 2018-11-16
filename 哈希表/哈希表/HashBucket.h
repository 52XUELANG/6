#define _CRT_SECURE_NO_WARNINGS

#ifndef __HASHBUCKET_H__
#define __HASHBUCKET_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#define MAX_SIZE 10
typedef int HNDataType;
typedef  struct HashNode
{
	struct HashNode* _pNext;
	HNDataType _data;
}HashNode, *pHashNode;
typedef size_t (*PElemToInt)(HNDataType data);
typedef struct HashBucket
{
	pHashNode* _table;
	int _capacity;
	int _size;
	PElemToInt _pElemToInt;
}HashBucket,*pHashBucket;

void HashBucketInit(pHashBucket ht, int capacity, PElemToInt pElemToInt);//初始化
void HashBuctetInsertUnique(pHashBucket ht, HNDataType data);//插入不可重复的元素
void HashBucketInsertEqual(pHashBucket ht, HNDataType data);//插入可重复的元素
void HashDeleteUnique(pHashBucket ht, HNDataType data);//删除无重复的元素
void HashDeleteEqual(pHashBucket ht, HNDataType data);//删除重复的元素
pHashNode HashBucketFind(pHashBucket ht, HNDataType data);//查找
int HashBucketSize(pHashBucket ht);//大小
int HashBucketEmpty(pHashBucket ht);//判空
int HashBucketDestroy(pHashBucket ht);//销毁哈希表
int HashBucketFunc(pHashBucket ht,HNDataType data);//哈希函数
pHashNode BuyHashNode(HNDataType data);//创建结点
int HashBucketCheckCapacity(pHashBucket ht);//增容

#endif