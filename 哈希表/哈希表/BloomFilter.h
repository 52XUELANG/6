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
	BitMap _bfBitMap;//λͼ
	int _size;
	PStrToInt _pSTInt[5];
}BloomFilter,*pBloomFilter;

void BloomFilterInit(pBloomFilter bf, int capacity,PStrToInt* STInt);//��ʼ��,��������ָ�룬ָ��5����ϣ����
int BloomFilterIsIn(pBloomFilter bf, BFDatatype data);//ȷ�ϴ���
void BloomFilterInsert(pBloomFilter bf, BFDatatype str);//����


#endif