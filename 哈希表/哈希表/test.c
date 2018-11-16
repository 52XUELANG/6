#define _CRT_SECURE_NO_WARNINGS
#include"hash.h"
#include"HashBucket.h"
#include"common.h"
#include"BitMap.h"
#include"BloomFilter.h"
int main()
{
#if 0
	HashTable ht;
	HashTableInit(&ht,1);
	HashTableInsert(&ht, 23);
	HashTableInsert(&ht, 14);
	HashTableInsert(&ht, 74);
	HashTableInsert(&ht, 33);
	HashTableInsert(&ht, 19);
	HashTableInsert(&ht, 29);

	printf("%d\n",HashTableSize(&ht));

	if (-1 != HashTableFind(&ht, 33))
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}

	if (-1 != HashTableFind(&ht, 3))
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}

	HashTableDelete(&ht, 33);

	printf("%d\n", HashTableSize(&ht));

	if (-1 != HashTableFind(&ht, 33))
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
#endif//静态测试

#if 0
	HashTable ht;
	HashTableInit(&ht, 10, 1);
	for (int i = 1; i < 6; i++)
	{
		HashTableInsert(&ht, i);
	}
	HashTableInsert(&ht, 23);
	HashTableInsert(&ht, 14);
	HashTableInsert(&ht, 74);
	HashTableInsert(&ht, 33);
	HashTableInsert(&ht, 19);
	HashTableInsert(&ht, 29);
	printf("%d\n", HashTableSize(&ht));

	if (-1 != HashTableFind(&ht, 33))
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}

	if (-1 != HashTableFind(&ht, 3))
	{
		printf("存在\n");
	}
	else
	{
		printf("不存在\n");
	}
	//HashTableDelete(&ht, 33);

	//printf("%d\n", HashTableSize(&ht));

	//if (-1 != HashTableFind(&ht, 33))
	//{
	//	printf("存在\n");
	//}
	//else
	//{
	//	printf("不存在\n");
	//}

#endif//动态存放数测试

	/*HashTable ht;//哈希表
	HashTableInit(&ht, 10, 1);
	HashTableInsert(&ht, "东邪");
	HashTableInsert(&ht, "西毒");
	HashTableInsert(&ht, "南帝");
	HashTableInsert(&ht, "北丐");*/

	//HashBucket ht1 ;//哈希桶（开散列）
	//HashBucketInit(&ht1, 10, UnStrToInt);
	//HashBuctetInsertUnique(&ht1, 1);
	//HashBuctetInsertUnique(&ht1, 11);
	//HashBuctetInsertUnique(&ht1, 54);
	//HashBuctetInsertUnique(&ht1, 2);
	//HashBuctetInsertUnique(&ht1, 3);
	//HashBuctetInsertUnique(&ht1, 4);
	//HashBuctetInsertUnique(&ht1, 5);


	//BitMap bm;//位图
	//int arr[] = { 1, 3, 7, 4, 12, 16, 19, 13, 22, 18 };
	//BitMapInit(&bm,10000000000);
	//for (int i = 0; i<  sizeof(arr)/sizeof(arr[0]); i++)
	//{
	//	BitMapSet(&bm, arr[i]);
	//}
	//printf("总比特个数：%d\n",BitMapSize(&bm));
	//printf("比特位为1的个数：%d\n",BitMapCount(&bm));
	//if (BitMapTest(&bm, 16))
	//{
	//	printf("%d",1);
	//}
	//else
	//{
	//	printf("%d",0);
	//}
	//BitMapReSet(&bm, 16);
	//printf("总比特个数：%d\n", BitMapSize(&bm));
	//printf("比特位为1的个数：%d\n", BitMapCount(&bm));
	//if (BitMapTest(&bm, 16))
	//{
	//	printf("%d",1);
	//}
	//else
	//{
	//	printf("%d",0);
	//}


	BloomFilter bf;
	PStrToInt STInt[] = { StrToInt1, StrToInt2, StrToInt3, StrToInt4, StrToInt5 };
	BloomFilterInit(&bf, 100, STInt);

	BloomFilterInsert(&bf,"吞日者");
	BloomFilterInsert(&bf, "死亡步枪");
	BloomFilterInsert(&bf, "夕阳骑士");
	BloomFilterInsert(&bf, "旋风斗星弩");
	BloomFilterInsert(&bf, "枪械之神—闪");
	if (BloomFilterIsIn(&bf,"吞日者"))
	{
		printf("在！\n");
	}
	else
	{
		printf("不在!\n");
	}



	if (BloomFilterIsIn(&bf, "乌尔班攻城巨炮"))
	{
		printf("在！\n");
	}
	else
	{
		printf("不在!\n");
	}


	system("pause");
	return 0;
}