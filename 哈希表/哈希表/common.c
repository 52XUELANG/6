#define _CRT_SECURE_NO_WARNINGS
#include"common.h"

unsigned long PrimeSize[PRIME_SIZE] =
{
	3ul,53ul, 97ul, 193ul, 389ul, 769ul, 1543ul, 3079ul
};


size_t UnStrToInt(int data)//元素默认是整型数据，直接返回
{
	return data;
}

size_t StrToInt(const char* str)//元素是字符串，需要化成整型数据
{
	unsigned int seed = 131;
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash*seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

size_t GetNextPrime(int capacity)
{
	for (int i = 0; i < PRIME_SIZE;i++)
	{
		if (PrimeSize[i] > (size_t)capacity)
		{
			return PrimeSize[i];
		}
	}
	return PrimeSize[PRIME_SIZE - 1];
}

size_t StrToInt1(const char* str)
{
	unsigned int seed = 131;
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash*seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}
size_t StrToInt2(const char* str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash*a + (*str++);
		a *= b;
	}
	return (hash & 0x7FFFFFFF);
}
size_t StrToInt3(const char* str)
{
	unsigned int hash = 1315423911;
	while (*str)
	{
		hash ^= ((hash << 5) + (*str++) + (hash >> 2));
	}
	return (hash & 0x7FFFFFFF);
}
size_t StrToInt4(const char* str)
{
	unsigned int hash = 5381;
	while (*str)
	{
		hash += (hash << 5) + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}
size_t StrToInt5(const char* str)
{
	unsigned int hash = 0;
	unsigned i;
	for (i = 0; *str; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
		}
	}
	return (hash & 0x7FFFFFFF);
}
