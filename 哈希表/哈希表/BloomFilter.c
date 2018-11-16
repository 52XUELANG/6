#define _CRT_SECURE_NO_WARNINGS
#include"BloomFilter.h"

void BloomFilterInit(pBloomFilter bf, int capacity, PStrToInt* PSTInt)//��ʼ��
{
	assert(bf);
	BitMapInit(&(bf->_bfBitMap), capacity*5);//һ��Ԫ�ض�Ӧ5����ϣ����,��Ӧ5������λ
	bf->_size = 0;
	for (int i = 0; i < sizeof(bf->_pSTInt)/sizeof(bf->_pSTInt[0]); i++)
	{
		bf->_pSTInt[i] = PSTInt[i];//����ϣ���������������еĺ���
	}
}

void BloomFilterInsert(pBloomFilter bf, BFDatatype str)
{
	int hashAdd1, hashAdd2, hashAdd3, hashAdd4, hashAdd5;//5����ϣ������Ӧ5����ϣ��ַ

	hashAdd1 = bf->_pSTInt[0](str) % (bf->_bfBitMap._size);//λͼ�е�����,bf->_pSTInt[0](str)�ǽ��ַ���ת�����������ݵĺ���
	BitMapSet(&bf->_bfBitMap, hashAdd1);//��1

	hashAdd2 = bf->_pSTInt[1](str) % (bf->_bfBitMap._size);//λͼ�е�����,bf->_pSTInt[1](str)�ǽ��ַ���ת�����������ݵĺ���
	BitMapSet(&bf->_bfBitMap, hashAdd2);//��1

	hashAdd3 = bf->_pSTInt[2](str) % (bf->_bfBitMap._size);//λͼ�е�����,bf->_pSTInt[2](str)�ǽ��ַ���ת�����������ݵĺ���
	BitMapSet(&bf->_bfBitMap, hashAdd3);//��1

	hashAdd4 = bf->_pSTInt[3](str) % (bf->_bfBitMap._size);//λͼ�е�����,bf->_pSTInt[3](str)�ǽ��ַ���ת�����������ݵĺ���
	BitMapSet(&bf->_bfBitMap, hashAdd4);//��1

	hashAdd5 = bf->_pSTInt[4](str) % (bf->_bfBitMap._size);//λͼ�е�����,bf->_pSTInt[4](str)�ǽ��ַ���ת�����������ݵĺ���
	BitMapSet(&bf->_bfBitMap, hashAdd5);//��1

	bf->_size++;
}

int BloomFilterIsIn(pBloomFilter bf, BFDatatype data)//ȷ�ϴ���
{
	int hashAdd1, hashAdd2, hashAdd3, hashAdd4, hashAdd5;//5����ϣ������Ӧ5����ϣ��ַ
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