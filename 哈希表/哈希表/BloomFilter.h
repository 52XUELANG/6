#define _CRT_SECURE_NO_WARNINGS
#ifndef __BLOOMFILTER_H__
#define __BLOOMFILTER_H__

#include"BitMap.h"
#include<assert.h>
#include"common.h"

typedef char* BFDatatype;
typedef size_t (*PStrToInt) (const char* str);
typedef struct BloomFilter
{
	BitMap _bfBitMap;//位图
	int _size;
	PStrToInt _pSTInt[5];
}BloomFilter,*pBloomFilter;

void BloomFilterInit(pBloomFilter bf, int capacity,PStrToInt* STInt);//初始化,包含函数指针，指向5个哈希函数
int BloomFilterIsIn(pBloomFilter bf, BFDatatype data);//确认存在
void BloomFilterInsert(pBloomFilter bf, BFDatatype str);//插入


#endif