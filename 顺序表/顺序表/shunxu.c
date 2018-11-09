#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<assert.h>
#include"shunxu.h"


void SeqListPrint(SeqList* pSeq)//��ӡ
{
	size_t i = 0;
	for (i = 0; i <pSeq->_size; i++)
	{
		printf("%d ",pSeq->_a[i]);
	}
	printf("\n");
}

void SeqListInit(SeqList* pSeq)//��ʼ��
{
	memset(pSeq->_a,0,sizeof(DataType)*N);//�����ֽڳ�ʼ��Ϊ0
	pSeq->_size = 0;//�ṹ�������С

}

void SeqListPushBack(SeqList* pSeq, DataType x)//β��
{
	assert(pSeq);//���վ���
	if (pSeq->_size >= N)//�ж�˳����Ƿ���Ա
	{
		printf("˳���������\n");
		return;
	}
	else
	{
		pSeq->_a[pSeq->_size] = x;
		pSeq->_size++;
	}
}

void SeqListPushFront(SeqList* pSeq, DataType x)//ͷ��
{
	assert(pSeq);
	if (pSeq->_size>=N)
	{
		printf("˳�����!\n");
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

void SeqListPopBack(SeqList* pSeq)//βɾ��
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("˳���Ϊ��\n");
		return;
	}
	else
	{
		/*pSeq->_a[pSeq->_size-1] = '\0';*/
		//���Բ��øı�ֵΪ0������ֱ�Ӳ���ʾ
		pSeq->_size--;
	}
}

void SeqListPopFront(SeqList* pSeq)//ͷɾ��
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("˳���Ϊ�գ��޷�ɾ��\n");
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

void SeqListInsert(SeqList* pSeq, size_t pos, DataType x)//ָ��λ�ò��룬��posΪpSeq->sizeʱ����Ϊβ�壬Ϊ0ʱ����Ϊͷ��
{
	assert(pSeq);
	assert(pos<=pSeq->_size);//pos��ֵ���ɳ���size
	if (pSeq->_size == N)
	{
		printf("����\n");
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

void SeqListErase(SeqList* pSeq, size_t pos)//ָ��λ��ɾ��,��posΪpSeq->size-1ʱ����Ϊβɾ��Ϊ0ʱ����Ϊͷɾ��ĳЩ����£�������Ҫ���
{
	assert(pSeq);
	assert(pos < pSeq->_size);
	if (pSeq->_size == 0)
	{
		printf("�յ�");
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

int SeqListFind(SeqList* pSeq, DataType x)//����
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

void SeqListModify(SeqList* pSeq,size_t pos,DataType x)//�޸�
{
	assert(pSeq);
	assert(pos<pSeq->_size);
	pSeq->_a[pos] = x;
}

void SeqListRemove(SeqList* pSeq, DataType x)//ɾ��ָ��Ԫ��
{
	int pos = SeqListFind(pSeq, x);
	SeqListErase(pSeq, pos);
}

void SeqListRemoveAll(SeqList* pSeq, DataType x)//ɾ������ָ��Ԫ��
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
		
	}*//*����һ����ʱ��*/

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
	pSeq->_size = count;//ʱ�临�Ӷȣ�O(n)����һ��
}

void SeqListBubble(SeqList* pSeq)//ð������
{
	assert(pSeq);
	while (1)
	{
		printf("ѡ�������ǽ���0������\t1������\n");
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
			printf("�������\n");
		}
	}
}

void SeqListSelectSort(SeqList* pSeq)//ѡ������
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

void SeqListBinarySearch(SeqList* pSeq,DataType x)//���ֲ���
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
			printf("�������±�:%d\n",mid);
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
	printf("û�в��ҵ���\n");
	return;
}




