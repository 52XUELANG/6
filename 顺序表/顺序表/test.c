#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"shunxu.h"
#include<assert.h>


test()
{
	SeqList s;
	int pos = 0;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);//β��
	SeqListPrint(&s);//��ӡ
	SeqListPushFront(&s, 5);//ͷ��
	SeqListPrint(&s);//��ӡ
	SeqListPopBack(&s);//βɾ��
	SeqListPrint(&s);//��ӡ
	SeqListPopFront(&s);//ͷɾ��
	SeqListPrint(&s);//��ӡ
	SeqListInsert(&s, pos, 5);//ָ��λ�ò���
	SeqListPrint(&s);//��ӡ
	SeqListErase(&s, pos);//ָ��λ��ɾ��
	SeqListPrint(&s);//��ӡ
	int iFind = 0;
	iFind = SeqListFind(&s, 2);//����
	printf("%d\n",iFind);
	SeqListModify(&s,2,6);//�޸�
	SeqListPrint(&s);//��ӡ
}

test2()
{
	SeqList s;
	int pos = 0;
	SeqListInit(&s);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 7);
	//SeqListRemove(&s,2);//ɾ��ָ��Ԫ��
	SeqListPrint(&s);//��ӡ
	//SeqListRemoveAll(&s, 2);//ɾ������ָ��Ԫ��
	//SeqListPrint(&s);//��ӡ
	//SeqListBubble(&s);//ð������
	//SeqListPrint(&s);//��ӡ
	SeqListSelectSort(&s);//ѡ������
	SeqListPrint(&s);//��ӡ
	SeqListBinarySearch(&s,3);//���ֲ���
}

int main()
{
	/*test();*/
	test2();
	system("pause");
	return 0;
}