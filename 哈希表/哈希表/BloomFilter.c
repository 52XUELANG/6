#define _CRT_SECURE_NO_WARNINGS
#include"BloomFilter.h"

void BloomFilterInit(pBloomFilter bf, int capacity, PStrToInt* PSTInt)//初始化
{
	assert(bf);
	BitMapInit(&(bf->_bfBitMap), capacity*5);//一个元素对应5个哈希函数,对应5个比特位
	bf->_size = 0;
	for (int i = 0; i < sizeof(bf->_pSTInt)/sizeof(bf->_pSTInt[0]); i++)
	{
		bf->_pSTInt[i] = PSTInt[i];//将哈希函数赋给过滤器中的函数
	}
}

void BloomFilterInsert(pBloomFilter bf, BFDatatype str)
{
	int hashAdd1, hashAdd2, hashAdd3, hashAdd4, hashAdd5;//5个哈希函数对应5个哈希地址

	hashAdd1 = bf->_pSTInt[0](str) % (bf->_bfBitMap._size);//位图中的容量,bf->_pSTInt[0](str)是将字符串转化成整型数据的函数
	BitMapSet(&bf->_bfBitMap, hashAdd1);//置1

	hashAdd2 = bf->_pSTInt[1](str) % (bf->_bfBitMap._size);//位图中的容量,bf->_pSTInt[1](str)是将字符串转化成整型数据的函数
	BitMapSet(&bf->_bfBitMap, hashAdd2);//置1

	hashAdd3 = bf->_pSTInt[2](str) % (bf->_bfBitMap._size);//位图中的容量,bf->_pSTInt[2](str)是将字符串转化成整型数据的函数
	BitMapSet(&bf->_bfBitMap, hashAdd3);//置1

	hashAdd4 = bf->_pSTInt[3](str) % (bf->_bfBitMap._size);//位图中的容量,bf->_pSTInt[3](str)是将字符串转化成整型数据的函数
	BitMapSet(&bf->_bfBitMap, hashAdd4);//置1

	hashAdd5 = bf->_pSTInt[4](str) % (bf->_bfBitMap._size);//位图中的容量,bf->_pSTInt[4](str)是将字符串转化成整型数据的函数
	BitMapSet(&bf->_bfBitMap, hashAdd5);//置1

	bf->_size++;
}

int BloomFilterIsIn(pBloomFilter bf, BFDatatype data)//确认存在
{
	int hashAdd1, hashAdd2, hashAdd3, hashAdd4, hashAdd5;//5个哈希函数对应5个哈希地址
	hashAdd1 = bf->_pSTInt[0](data) % (bf->_bfBitMap._size);
	if (BitMapTest(&(bf->_bfBitMap), hashAdd1) == 0)
	{
		return 0;
	}

	hashAdd2 = bf->_pSTInt[1](data) % (bf->_bfBitMap._size);
	if (BitMapTest(&(bf->_bfBitMap), hashAdd2) == 0)
	{
		return 0;
	}

	hashAdd3 = bf->_pSTInt[2](data) % (bf->_bfBitMap._size);
	if (BitMapTest(&(bf->_bfBitMap), hashAdd3) == 0)
	{
		return 0;
	}

	hashAdd4 = bf->_pSTInt[3](data) % (bf->_bfBitMap._size);
	if (BitMapTest(&(bf->_bfBitMap), hashAdd4) == 0)
	{
		return 0;
	}

	hashAdd5 = bf->_pSTInt[4](data) % (bf->_bfBitMap._size);
	if (BitMapTest(&(bf->_bfBitMap), hashAdd5) == 0)
	{
		return 0;
	}

	return 1;
}