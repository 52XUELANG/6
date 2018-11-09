#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<assert.h>
#include"shunxu.h"


void SeqListPrint(SeqList* pSeq)//打印
{
	size_t i = 0;
	for (i = 0; i <pSeq->_size; i++)
	{
		printf("%d ",pSeq->_a[i]);
	}
	printf("\n");
}

void SeqListInit(SeqList* pSeq)//初始化
{
	memset(pSeq->_a,0,sizeof(DataType)*N);//所有字节初始化为0
	pSeq->_size = 0;//结构体数组大小

}

void SeqListPushBack(SeqList* pSeq, DataType x)//尾插
{
	assert(pSeq);//防空警告
	if (pSeq->_size >= N)//判断顺序表是否满员
	{
		printf("顺序表已满！\n");
		return;
	}
	else
	{
		pSeq->_a[pSeq->_size] = x;
		pSeq->_size++;
	}
}

void SeqListPushFront(SeqList* pSeq, DataType x)//头插
{
	assert(pSeq);
	if (pSeq->_size>=N)
	{
		printf("顺序表满!\n");
		return;
	}
	else
	{
		int end = pSeq->_size - 1;
		while (end>=0)
		{
			pSeq->_a[end+1] = pSeq->_a[end];
			end--;
		}
		pSeq->_a[0] = x;
		pSeq->_size++;
	}
}

void SeqListPopBack(SeqList* pSeq)//尾删除
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	else
	{
		/*pSeq->_a[pSeq->_size-1] = '\0';*/
		//可以不用改变值为0，可以直接不显示
		pSeq->_size--;
	}
}

void SeqListPopFront(SeqList* pSeq)//头删除
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	else
	{
		int start = 1;
		while (start<(int)(pSeq->_size))
		{
			pSeq->_a[start - 1] = pSeq->_a[start];
			start++;
		}
		pSeq->_size--;
	}
}

void SeqListInsert(SeqList* pSeq, size_t pos, DataType x)//指定位置插入，当pos为pSeq->size时，变为尾插，为0时，变为头插
{
	assert(pSeq);
	assert(pos<=pSeq->_size);//pos的值不可超过size
	if (pSeq->_size == N)
	{
		printf("满了\n");
		return;
	}
	else
	{
		int end = 0;
		for (end = pSeq->_size-1; end >= (int)pos;)
		{
			pSeq->_a[end+1] = pSeq->_a[end];
			end--;
		}
		pSeq->_a[pos] = x;
		pSeq->_size++;
	}
}

void SeqListErase(SeqList* pSeq, size_t pos)//指定位置删除,当pos为pSeq->size-1时，变为尾删，为0时，变为头删，某些情况下，表内仍要查空
{
	assert(pSeq);
	assert(pos < pSeq->_size);
	if (pSeq->_size == 0)
	{
		printf("空的");
		return;
	}
	else
	{
		while (pos<pSeq->_size-1)
		{
			pSeq->_a[pos] = pSeq->_a[pos + 1];
			pos++;
		}
		pSeq->_size--;
	}
}

int SeqListFind(SeqList* pSeq, DataType x)//查找
{
	assert(pSeq);
	for (int i = 0; i < (int)pSeq->_size; i++)
	{
		if (pSeq->_a[i]==x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListModify(SeqList* pSeq,size_t pos,DataType x)//修改
{
	assert(pSeq);
	assert(pos<pSeq->_size);
	pSeq->_a[pos] = x;
}

void SeqListRemove(SeqList* pSeq, DataType x)//删除指定元素
{
	int pos = SeqListFind(pSeq, x);
	SeqListErase(pSeq, pos);
}

void SeqListRemoveAll(SeqList* pSeq, DataType x)//删除所有指定元素
{
	assert(pSeq);
	/*int pos1 = 0;
	int pos2 = 0;
	int count = 0;
	while (pSeq->_a[pos1]!=0)
	{
		if (pSeq->_a[pos2] != x)
		{
			pos1++;
			pos2++;
		}
		else
		{
			while (pSeq->_a[pos1]==2)
			{
				pos1++;
			}
			while (pos1<=pSeq->_size-1)
			{
				pSeq->_a[pos2] = pSeq->_a[pos1];
				pos1++;
				pos2++;
			}
			pSeq->_size--;
			pos1 = 0;
			pos2 = 0;
		}
		
	}*//*方案一：费时间*/

	int count = 0;
	int i = 0;
	while (i<(int)pSeq->_size)
	{
		if (pSeq->_a[i] == x)
		{
			i++;
		}
		else
		{
			pSeq->_a[count] = pSeq->_a[i];
			i++;
			count++;
		}
	}
	pSeq->_size = count;//时间复杂度：O(n)遍历一次
}

void SeqListBubble(SeqList* pSeq)//冒泡排序
{
	assert(pSeq);
	while (1)
	{
		printf("选择升序还是降序：0、升序\t1、降序\n");
		int choice = 0;
		scanf("%d",&choice);
		if (choice == 0)
		{
			int j = 0;
			int end = pSeq->_size - 2;
			int inspect = 0;
			while (end > 0)
			{
				while (j <= end)
				{
					if (pSeq->_a[j] > pSeq->_a[j + 1])
					{
						pSeq->_a[j] ^= pSeq->_a[j + 1];
						pSeq->_a[j + 1] ^= pSeq->_a[j];
						pSeq->_a[j] ^= pSeq->_a[j + 1];
						inspect = 1;
					}
					j++;
				}
				if (inspect == 0)
				{
					printf("%d\n", inspect);
					break;
				}
				end--;
				j = 0;
			}
			break;
		}
		else if (choice == 1)
		{

			int j = 0;
			int end = pSeq->_size - 2;
			int inspect = 0;
			while (end > 0)
			{
				while (j <= end)
				{
					if (pSeq->_a[j] < pSeq->_a[j + 1])
					{
						pSeq->_a[j] ^= pSeq->_a[j + 1];
						pSeq->_a[j + 1] ^= pSeq->_a[j];
						pSeq->_a[j] ^= pSeq->_a[j + 1];
						inspect = 1;
					}
					j++;
				}
				if (inspect == 0)
				{
					printf("%d\n", inspect);
					break;
				}
				end--;
				j = 0;
			}
			break;
		}
		else
		{
			printf("输入错误！\n");
		}
	}
}

void SeqListSelectSort(SeqList* pSeq)//选择排序
{
	assert(pSeq);
	int left = 0;
	int right = (pSeq->_size - 1);
	int min = 0;
	int max = 0;
	int tmp = 0;
	while (left<=right)
	{
		min = left;
		max = left;
		while (max<right)
		{
			if (pSeq->_a[max]>pSeq->_a[right])
			{
				tmp = pSeq->_a[max];
				pSeq->_a[max] = pSeq->_a[right];
				pSeq->_a[right] = tmp;
			}
			max++;
		}
		while (min<right)
		{
			if (pSeq->_a[min]<pSeq->_a[left])
			{
				tmp = pSeq->_a[min];
				pSeq->_a[min] = pSeq->_a[left];
				pSeq->_a[left] = tmp;
			}
			min++;
		}
		left++;
		right--;
	}
	
}

void SeqListBinarySearch(SeqList* pSeq,DataType x)//二分查找
{
	assert(pSeq);
	int mid =0;
	int left = 0;
	int right = pSeq->_size - 1;
	while (left<=right)
	{
		mid = left+(right-left)/2;
		if (pSeq->_a[mid]==x)
		{
			printf("查找数下标:%d\n",mid);
			return;
		}
		else if (pSeq->_a[mid]<x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	printf("没有查找的数\n");
	return;
}




