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

void HashBucketInit(pHashBucket ht, int capacity, PElemToInt pElemToInt);//��ʼ��
void HashBuctetInsertUnique(pHashBucket ht, HNDataType data);//���벻���ظ���Ԫ��
void HashBucketInsertEqual(pHashBucket ht, HNDataType data);//������ظ���Ԫ��
void HashDeleteUnique(pHashBucket ht, HNDataType data);//ɾ�����ظ���Ԫ��
void HashDeleteEqual(pHashBucket ht, HNDataType data);//ɾ���ظ���Ԫ��
pHashNode HashBucketFind(pHashBucket ht, HNDataType data);//����
int HashBucketSize(pHashBucket ht);//��С
int HashBucketEmpty(pHashBucket ht);//�п�
int HashBucketDestroy(pHashBucket ht);//���ٹ�ϣ��
int HashBucketFunc(pHashBucket ht,HNDataType data);//��ϣ����
pHashNode BuyHashNode(HNDataType data);//�������
int HashBucketCheckCapacity(pHashBucket ht);//����

#endif