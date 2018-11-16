#define _CRT_SECURE_NO_WARNINGS
#include"BitMap.h"

void BitMapInit(pBitMap bm, unsigned long capacity)//��ʼ��
{
	assert(bm);
	bm->_capacity = (capacity / 32) + 1;//����ȡֵ
	bm->_bitset = (int*)calloc(bm->_capacity, sizeof(int));
	if (bm->_bitset == NULL)
	{
		assert(0);
		return;
	}
	bm->_size = capacity;
}
void BitMapSet(pBitMap bm, int pos)//��1��ʾ������
{
	int index = pos / 32;//index��ʾ����һ������οռ䣬int32������λ
	int index_bit = pos % 32;//��ʾ�ڵ�ǰ���οռ����һ������λ
	if (pos < bm->_size)
	{
		bm->_bitset[index] |= (1 << index_bit);
	}
	else
	{
		return;
	}
}
void BitMapReSet(pBitMap bm, int pos)//��0��ʾ������
{
	int index = pos / 32;//index��ʾ����һ������οռ䣬int32������λ
	int index_bit = pos % 32;//��ʾ�ڵ�ǰ���οռ����һ������λ
	if (pos < bm->_size)
	{
		bm->_bitset[index] &= (~(1 << index_bit));
	}
	else
	{
		return;
	}
}
int BitMapTest(pBitMap bm, int pos)//�鿴ĳλ�õ�0/1��ʾ
{
	int index = pos / 32;//index��ʾ����һ������οռ䣬int32������λ
	int index_bit = pos % 32;//��ʾ�ڵ�ǰ���οռ����һ������λ
	if (pos < bm->_size)
	{
		return bm->_bitset[index] & (1 << index_bit);
	}
	else
	{
		return 0;
	}
}
int BitMapSize(pBitMap bm)//���С
{
	return bm->_size;
}
int BitMapCount(pBitMap bm)//���ڶ��ٸ�1
{
	const char* bitCount = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";//0��15��4������λ���ж��ٸ�1
	int count = 0;
	for (int i = 0; i < (bm->_capacity); i++)
	{
		int value = bm->_bitset[i];
		int j = 0;
		while (j<sizeof(bm->_bitset[0]))
		{
			char c = value;//cΪ1���ֽڣ�8������λ
			count += bitCount[c&(0x0f)];
			c >>= 4;//bitCountֻ��ͳ��4������λ,����4λ�����Ƚ�
			count += bitCount[c&(0x0f)];
			value >>= 8;//�ȽϽ���������8λ������һ���ֽ�
			j++;
		}
	}
	return count;
}
void BitMapDestropy(pBitMap bm)//����
{
	if (bm->_bitset)
	{
		free(bm->_bitset);
		bm->_capacity = 0;
		bm->_size = 0;
	}
}