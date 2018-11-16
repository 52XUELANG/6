#define _CRT_SECURE_NO_WARNINGS

/*
二次探测：防止数据堆积
二次探测的隐性问题：数据数量接近散列表长度时，空的哈希地址找到的几率变小，时间损耗
哈希表优化：1.静态转化为动态(malloc申请堆空间)；
2.存放类型的扩展(common.c文件的函数，将字符串转化成整形)；
3.哈希函数的优化(哈希函数优化为模取素数：定义素数表，根据给定容量获取模取素数)
负载因子：数据数量/散列表长度(0.7以下)



开散列：将哈希表的表地址存储的内容从元素改为一个链表，当发生哈希冲突时，对当前地址存储的链表进行头插操作
HashBucket:哈希桶(开散列)


位图BitMap:将整型数按比特位的位置存放，该数存在，将对应比特位的0换成1，表示存在，节省空间和降低寻找的时间复杂度

布隆过滤器BloomFilter:将非整型数据（例如字符串）用多个哈希函数计算出多个哈希地址，按照位图的方式存储。当找一个数据时，用哈希函数算出各个哈希地址，若都为1，表示该数据存在
*/

#if 0
#ifndef __HASH_H__
#define __HASH_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX_SIZE 10
typedef enum{ EXIST, EMPTY, DELETE }State;//状态
typedef int DataType;

typedef struct HashElem
{
	DataType _data;
	State _state;
}HashElem;

typedef struct HashTable
{
	HashElem _array[MAX_SIZE];
	int _size;//记录哈希表的有效个数
	int _total;//记录个数（包括存在和删除的）
	int _IsLineDetective;//探测方式
}HashTable,*pHashTable;

void HashTableInit(pHashTable ht,int IsLineDetective);//初始化
void HashTableInsert(pHashTable ht,DataType data);//插入
void HashTableDelete(pHashTable ht,DataType data);//删除
int HashTableFind(pHashTable ht,DataType data);//查找
int HashTableSize(pHashTable ht);//大小
int HashTableEmpty(pHashTable ht);//判空
int HashFunc(DataType data);//哈希函数
int Detective(int HashIp);//线性探测
int Detective2(int HashIp,int i);//二次探测

#endif

#endif//静态哈希表


#ifndef __HASH_H__
#define __HASH_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

#define MAX_SIZE 10

typedef enum{ EXIST, EMPTY, DELETE }State;//状态
//typedef int DataType;
typedef char* DataType;

typedef struct HashElem
{
	DataType _data;//数据
	State _state;//标志
}HashElem;

typedef struct HashTable
{
	HashElem* _array;//散列表
	int _capacity;//容量
	int _size;//记录哈希表的有效个数
	int _IsLineDetective;//探测方式
}HashTable, *pHashTable;

void HashTableInit(pHashTable ht, int capacity, int IsLineDetective);//初始化
void HashTableInsert(pHashTable ht, DataType data);//插入
void HashTableDelete(pHashTable ht, DataType data);//删除
int HashTableFind(pHashTable ht, DataType data);//查找
int HashTableSize(pHashTable ht);//大小
int HashTableEmpty(pHashTable ht);//判空
int HashFunc(DataType data);//哈希函数
int Detective(int HashIp, pHashTable ht);//线性探测
int Detective2(int HashIp, int i);//二次探测
int CheckCapacity(pHashTable ht);//增容
void HashTableDestroy(pHashTable ht);//销毁
void HashTableSwap(pHashTable ht,pHashTable newHt);//交换

#endif
