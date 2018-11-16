#define _CRT_SECURE_NO_WARNINGS

#ifndef __BITMAP_H__
#define __BITMAP_H__

#include<assert.h>
#include<malloc.h>
#include<stdio.h>

typedef struct BitMap
{
	int* _bitset;
	int _capacity;
	int _size;//有效比特位的个数
}BitMap,*pBitMap;

void BitMapInit(pBitMap bm,unsigned int capacity);//初始化
void BitMapSet(pBitMap bm, int pos);//置1表示数存在
void BitMapReSet(pBitMap bm, int pos);//置0表示数存在
int BitMapTest(pBitMap bm, int pos);//查看某位置的0/1表示
int BitMapSize(pBitMap bm);//查大小
int BitMapCount(pBitMap bm);//存在多少个1
void BitMapDestropy(pBitMap bm);//销毁

#endif