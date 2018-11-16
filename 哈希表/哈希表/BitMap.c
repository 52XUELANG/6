#define _CRT_SECURE_NO_WARNINGS
#include"BitMap.h"

void BitMapInit(pBitMap bm, unsigned long capacity)//初始化
{
	assert(bm);
	bm->_capacity = (capacity / 32) + 1;//容量取值
	bm->_bitset = (int*)calloc(bm->_capacity, sizeof(int));
	if (bm->_bitset == NULL)
	{
		assert(0);
		return;
	}
	bm->_size = capacity;
}
void BitMapSet(pBitMap bm, int pos)//置1表示数存在
{
	int index = pos / 32;//index表示在哪一块儿整形空间，int32个比特位
	int index_bit = pos % 32;//表示在当前整形空间的哪一个比特位
	if (pos < bm->_size)
	{
		bm->_bitset[index] |= (1 << index_bit);
	}
	else
	{
		return;
	}
}
void BitMapReSet(pBitMap bm, int pos)//置0表示数存在
{
	int index = pos / 32;//index表示在哪一块儿整形空间，int32个比特位
	int index_bit = pos % 32;//表示在当前整形空间的哪一个比特位
	if (pos < bm->_size)
	{
		bm->_bitset[index] &= (~(1 << index_bit));
	}
	else
	{
		return;
	}
}
int BitMapTest(pBitMap bm, int pos)//查看某位置的0/1表示
{
	int index = pos / 32;//index表示在哪一块儿整形空间，int32个比特位
	int index_bit = pos % 32;//表示在当前整形空间的哪一个比特位
	if (pos < bm->_size)
	{
		return bm->_bitset[index] & (1 << index_bit);
	}
	else
	{
		return 0;
	}
}
int BitMapSize(pBitMap bm)//查大小
{
	return bm->_size;
}
int BitMapCount(pBitMap bm)//存在多少个1
{
	const char* bitCount = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";//0到15的4个比特位中有多少个1
	int count = 0;
	for (int i = 0; i < (bm->_capacity); i++)
	{
		int value = bm->_bitset[i];
		int j = 0;
		while (j<sizeof(bm->_bitset[0]))
		{
			char c = value;//c为1个字节，8个比特位
			count += bitCount[c&(0x0f)];
			c >>= 4;//bitCount只能统计4个比特位,右移4位继续比较
			count += bitCount[c&(0x0f)];
			value >>= 8;//比较结束，右移8位，到下一个字节
			j++;
		}
	}
	return count;
}
void BitMapDestropy(pBitMap bm)//销毁
{
	if (bm->_bitset)
	{
		free(bm->_bitset);
		bm->_capacity = 0;
		bm->_size = 0;
	}
}