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
	SeqListPushBack(&s, 4);//尾插
	SeqListPrint(&s);//打印
	SeqListPushFront(&s, 5);//头插
	SeqListPrint(&s);//打印
	SeqListPopBack(&s);//尾删除
	SeqListPrint(&s);//打印
	SeqListPopFront(&s);//头删除
	SeqListPrint(&s);//打印
	SeqListInsert(&s, pos, 5);//指定位置插入
	SeqListPrint(&s);//打印
	SeqListErase(&s, pos);//指定位置删除
	SeqListPrint(&s);//打印
	int iFind = 0;
	iFind = SeqListFind(&s, 2);//查找
	printf("%d\n",iFind);
	SeqListModify(&s,2,6);//修改
	SeqListPrint(&s);//打印
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
	//SeqListRemove(&s,2);//删除指定元素
	SeqListPrint(&s);//打印
	//SeqListRemoveAll(&s, 2);//删除所有指定元素
	//SeqListPrint(&s);//打印
	//SeqListBubble(&s);//冒泡排序
	//SeqListPrint(&s);//打印
	SeqListSelectSort(&s);//选择排序
	SeqListPrint(&s);//打印
	SeqListBinarySearch(&s,3);//二分查找
}

int main()
{
	/*test();*/
	test2();
	system("pause");
	return 0;
}