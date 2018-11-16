#define _CRT_SECURE_NO_WARNINGS

/*
����̽�⣺��ֹ���ݶѻ�
����̽����������⣺���������ӽ�ɢ�б���ʱ���յĹ�ϣ��ַ�ҵ��ļ��ʱ�С��ʱ�����
��ϣ���Ż���1.��̬ת��Ϊ��̬(malloc����ѿռ�)��
2.������͵���չ(common.c�ļ��ĺ��������ַ���ת��������)��
3.��ϣ�������Ż�(��ϣ�����Ż�Ϊģȡ�������������������ݸ���������ȡģȡ����)
�������ӣ���������/ɢ�б���(0.7����)



��ɢ�У�����ϣ��ı��ַ�洢�����ݴ�Ԫ�ظ�Ϊһ��������������ϣ��ͻʱ���Ե�ǰ��ַ�洢���������ͷ�����
HashBucket:��ϣͰ(��ɢ��)


λͼBitMap:��������������λ��λ�ô�ţ��������ڣ�����Ӧ����λ��0����1����ʾ���ڣ���ʡ�ռ�ͽ���Ѱ�ҵ�ʱ�临�Ӷ�

��¡������BloomFilter:�����������ݣ������ַ������ö����ϣ��������������ϣ��ַ������λͼ�ķ�ʽ�洢������һ������ʱ���ù�ϣ�������������ϣ��ַ������Ϊ1����ʾ�����ݴ���
*/

#if 0
#ifndef __HASH_H__
#define __HASH_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 10
typedef enum{ EXIST, EMPTY, DELETE }State;//״̬
typedef int DataType;

typedef struct HashElem
{
	DataType _data;
	State _state;
}HashElem;

typedef struct HashTable
{
	HashElem _array[MAX_SIZE];
	int _size;//��¼��ϣ�����Ч����
	int _total;//��¼�������������ں�ɾ���ģ�
	int _IsLineDetective;//̽�ⷽʽ
}HashTable,*pHashTable;

void HashTableInit(pHashTable ht,int IsLineDetective);//��ʼ��
void HashTableInsert(pHashTable ht,DataType data);//����
void HashTableDelete(pHashTable ht,DataType data);//ɾ��
int HashTableFind(pHashTable ht,DataType data);//����
int HashTableSize(pHashTable ht);//��С
int HashTableEmpty(pHashTable ht);//�п�
int HashFunc(DataType data);//��ϣ����
int Detective(int HashIp);//����̽��
int Detective2(int HashIp,int i);//����̽��

#endif

#endif//��̬��ϣ��


#ifndef __HASH_H__
#define __HASH_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

#define MAX_SIZE 10

typedef enum{ EXIST, EMPTY, DELETE }State;//״̬
//typedef int DataType;
typedef char* DataType;

typedef struct HashElem
{
	DataType _data;//����
	State _state;//��־
}HashElem;

typedef struct HashTable
{
	HashElem* _array;//ɢ�б�
	int _capacity;//����
	int _size;//��¼��ϣ�����Ч����
	int _IsLineDetective;//̽�ⷽʽ
}HashTable, *pHashTable;

void HashTableInit(pHashTable ht, int capacity, int IsLineDetective);//��ʼ��
void HashTableInsert(pHashTable ht, DataType data);//����
void HashTableDelete(pHashTable ht, DataType data);//ɾ��
int HashTableFind(pHashTable ht, DataType data);//����
int HashTableSize(pHashTable ht);//��С
int HashTableEmpty(pHashTable ht);//�п�
int HashFunc(DataType data);//��ϣ����
int Detective(int HashIp, pHashTable ht);//����̽��
int Detective2(int HashIp, int i);//����̽��
int CheckCapacity(pHashTable ht);//����
void HashTableDestroy(pHashTable ht);//����
void HashTableSwap(pHashTable ht,pHashTable newHt);//����

#endif
