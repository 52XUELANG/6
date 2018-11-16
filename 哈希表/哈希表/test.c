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
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}

	if (-1 != HashTableFind(&ht, 3))
	{
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}

	HashTableDelete(&ht, 33);

	printf("%d\n", HashTableSize(&ht));

	if (-1 != HashTableFind(&ht, 33))
	{
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}
#endif//��̬����

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
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}

	if (-1 != HashTableFind(&ht, 3))
	{
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}
	//HashTableDelete(&ht, 33);

	//printf("%d\n", HashTableSize(&ht));

	//if (-1 != HashTableFind(&ht, 33))
	//{
	//	printf("����\n");
	//}
	//else
	//{
	//	printf("������\n");
	//}

#endif//��̬���������

	/*HashTable ht;//��ϣ��
	HashTableInit(&ht, 10, 1);
	HashTableInsert(&ht, "��а");
	HashTableInsert(&ht, "����");
	HashTableInsert(&ht, "�ϵ�");
	HashTableInsert(&ht, "��ؤ");*/

	//HashBucket ht1 ;//��ϣͰ����ɢ�У�
	//HashBucketInit(&ht1, 10, UnStrToInt);
	//HashBuctetInsertUnique(&ht1, 1);
	//HashBuctetInsertUnique(&ht1, 11);
	//HashBuctetInsertUnique(&ht1, 54);
	//HashBuctetInsertUnique(&ht1, 2);
	//HashBuctetInsertUnique(&ht1, 3);
	//HashBuctetInsertUnique(&ht1, 4);
	//HashBuctetInsertUnique(&ht1, 5);


	//BitMap bm;//λͼ
	//int arr[] = { 1, 3, 7, 4, 12, 16, 19, 13, 22, 18 };
	//BitMapInit(&bm,10000000000);
	//for (int i = 0; i<  sizeof(arr)/sizeof(arr[0]); i++)
	//{
	//	BitMapSet(&bm, arr[i]);
	//}
	//printf("�ܱ��ظ�����%d\n",BitMapSize(&bm));
	//printf("����λΪ1�ĸ�����%d\n",BitMapCount(&bm));
	//if (BitMapTest(&bm, 16))
	//{
	//	printf("%d",1);
	//}
	//else
	//{
	//	printf("%d",0);
	//}
	//BitMapReSet(&bm, 16);
	//printf("�ܱ��ظ�����%d\n", BitMapSize(&bm));
	//printf("����λΪ1�ĸ�����%d\n", BitMapCount(&bm));
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

	BloomFilterInsert(&bf,"������");
	BloomFilterInsert(&bf, "������ǹ");
	BloomFilterInsert(&bf, "Ϧ����ʿ");
	BloomFilterInsert(&bf, "���綷����");
	BloomFilterInsert(&bf, "ǹе֮����");
	if (BloomFilterIsIn(&bf,"������"))
	{
		printf("�ڣ�\n");
	}
	else
	{
		printf("����!\n");
	}



	if (BloomFilterIsIn(&bf, "�ڶ��๥�Ǿ���"))
	{
		printf("�ڣ�\n");
	}
	else
	{
		printf("����!\n");
	}


	system("pause");
	return 0;
}