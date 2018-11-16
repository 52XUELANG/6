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
	int _size;//��Ч����λ�ĸ���
}BitMap,*pBitMap;

void BitMapInit(pBitMap bm,unsigned int capacity);//��ʼ��
void BitMapSet(pBitMap bm, int pos);//��1��ʾ������
void BitMapReSet(pBitMap bm, int pos);//��0��ʾ������
int BitMapTest(pBitMap bm, int pos);//�鿴ĳλ�õ�0/1��ʾ
int BitMapSize(pBitMap bm);//���С
int BitMapCount(pBitMap bm);//���ڶ��ٸ�1
void BitMapDestropy(pBitMap bm);//����

#endif