#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include<assert.h>
#include<string.h>

//void InitList(pList* pplist)//��ʼ��
//{
//	assert(pplist != NULL);//�п�
//	*pplist = NULL;
//}
pNode BuyNode(int d)//�������,���ؽ���ַ
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;
	return newNode;//���ش������ĵ�ַ
}

void PushBack(pList* pplist, int d)
{
	assert(NULL != pplist);
	if (*pplist == NULL)//������
	{
		pNode newNode = BuyNode(d);//�������
		*pplist = newNode;//�������Ĺҹ�����
	}
	else//�ǿ�����
	{
		pNode cur = *pplist;//����ָ��ָ������ͷ
		while (NULL != cur->next)
		{
			cur = cur->next;
		}//�������һ�����
		pNode newNode = BuyNode(d);
		cur->next = newNode;//���ҹ�
	}
}

void PrintList(pList plist)
{
	pNode cur = plist;
	while (NULL != cur)
	{
		printf("%d->",cur->data);//��ӡ��ǰ����
		cur = cur->next;//����
	}
	printf("over\n");
}

void DestroyList(pList* pplist)//����
{
	pNode cur = NULL;
	assert(NULL != *pplist);
	cur = *pplist;
	pNode del = NULL;
	while (NULL != cur)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}

int GetListLength(pList plist)//��������
{
	pNode cur = plist;
	int count = 0;
	while (NULL != cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void PopBack(pList* pplist)//β��ɾ��
{
	assert(NULL != pplist);
	if (*pplist == NULL)//������
	{
		return;
	}
	else
	if ((*pplist)->next == NULL)//һ�����
	{
		free(*pplist);
		*pplist = NULL;
	}
	else//һ�����ϵĽ��
	{
		pNode cur = *pplist;
		while (NULL != cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}

}

void PushFront(pList* pplist, int d)//ͷ����
{
	assert(pplist != NULL);
		pNode newNode = BuyNode(d);
		newNode->next = *pplist;
		*pplist = newNode;
}

void PopFront(pList* pplist)//ͷɾ��
{
	assert(pplist != NULL);
	if (*pplist == NULL)//������
	{
		return;
	}
	else
	if ((*pplist)->next == NULL)//һ�����
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		pNode cur = *pplist;
		*pplist = (*pplist)->next;
		free(cur);
		cur = NULL;
	}

}

pNode Find(pList plist, int d)//����
{
	assert((&plist)!=NULL);
	pNode cur = plist;
	while (cur!= NULL)
	{
		if (cur->data == d)
		{
			return cur;
			break;
		}
		cur = cur->next;
	}
	return NULL;
}

void Insert(pList* pplist, pNode pos, int d)//ָ��λ�ò���
{
	assert(pplist != NULL); 
	assert(*pplist != NULL);//������
	assert(pos != NULL);
	if (pos == *pplist)
	{
		PushFront(pplist, d);
	}
	else
	{
		pNode cur = NULL;
		cur = *pplist;
		while (cur->next!=NULL)
		{
			if (cur->next == pos)
			{
				pNode newNode = (pNode)malloc(sizeof(Node));
				newNode->next = NULL;
				newNode->data = 5;
				cur->next = newNode;
				newNode->next = pos;
				return;
			}
			else
			{
				cur = cur->next;
			}
		}
		printf("û����Ҫ�Ľ��");
		return;
	}
}

void Erase(pList* pplist, pNode pos)//ָ��λ��ɾ��
{
	assert(pplist != NULL);
	assert(pos != NULL);
	pNode del = pos;
	if (*pplist == NULL)//������
	{
		return;
	}
	else
	if (*pplist == pos)
	{
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	else
	{
		pNode cur = NULL;
		cur = *pplist;
		while (cur->next != NULL)
		{
			if (cur->next == pos)
			{
				cur->next = cur->next->next;
				free(del);
				del = NULL;
				return;
			}
			else
			{
				cur = cur->next;
			}
		}
		printf("û����Ҫ�Ľ��");
		return;
	}

}

void Remove(pList* pplist, int d)//ɾ��ָ��Ԫ�صĽ�㣬�������ò��Һ�ɾ���������
{
	
	assert(pplist != NULL);
	pNode cur = NULL;
	cur = *pplist;
	pNode del = NULL;
	while (cur!=NULL)
	{
		if (cur->data == d)
		{
			if (*pplist == cur)//��һ���ڵ�
			{
				*pplist = (*pplist)->next;
				free(cur);
				cur = NULL;
			}
			else//�ǵ�һ�����
			{
				del->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		else
		{
			del = cur;
			cur = cur->next;
		}
	}
}

void RemoveAll(pList* pplist, int d)//ɾ��ָ������Ԫ��
{
	assert(pplist != NULL);
	pNode cur = NULL;
	cur = *pplist;
	pNode del = NULL;
	while (cur != NULL)
	{
		if (cur->data == d)
		{
			if (*pplist == cur)//��һ���ڵ�
			{
				*pplist = (*pplist)->next;
				free(cur);
				cur = *pplist;
			}
			else//�ǵ�һ�����
			{
				del->next = cur->next;
				free(cur);
				cur = del;
			}
		}
		else
		{
			del = cur;
			cur = cur->next;
		}
	}
}

void TestPrintTailToHead(pList plist)//�����ӡ
{
	//if (plist == NULL)
	//{
	//	return;
	//}
	//else
	//{
	//	TestPrintTailToHead(plist->next);//�ݹ鷽������С����β����ʼ
	//	printf("%d->",plist->data);
	//}
	


	if (plist == NULL)//�ݹ鷽��
	{
		return;
	}
	else
	if (plist->next == NULL)
	{
		printf("%d",plist->data);
	}
	else
	{
		pNode cur = plist;
		pNode tail = NULL;
		while (tail != plist)
		{
			cur = plist;
			while (cur->next != tail )//tail��ʼ��ΪNULL����һ��ѭ��Ҳ������
			{
				cur = cur->next;
			}
			printf("%d->", cur->data);
			tail = cur;
		}
	}
}

void EraseNotTail(pNode pos)//ɾ����ͷ������ķ�β���
{
	//�滻ɾ����
	assert(pos != NULL);
	assert(pos->next != NULL);//�ж�β���
	pos->data = pos->next->data;
	pos->next = pos->next->next;
	free(pos->next);
	pos->next = NULL;
}

void InsertNode(pNode pos,int d)//��ͷ���֮ǰ����һ�����
{
	assert(pos != NULL);
	/*assert(pos != NULL);*/
	pNode newNode = (Node*)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;
	newNode->next = pos->next;
	pos->next = newNode;
	(pos->data) ^= (newNode->data);
	(newNode->data) ^= (pos->data);
	(pos->data) ^= (newNode->data);
}

void JosephusCycle(pList* pplist,int k)//Լɪ��
{
	pNode cur = *pplist;
	while (cur != cur->next)
	{
		pNode del = NULL;
		for (int i = 1; i < k; i++)
		{
			cur = cur->next;
		}
		printf("ɾ��:%d\n",cur->data);
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = cur->next->next;
		free(del);
		del = NULL;
	}
	printf("�Ҵ��ߣ�%d\n",cur->data);
}

void ReverseList(pList* pplist)//��ת������
{
	
	assert(pplist!=NULL);
	if (*pplist == NULL)
	{
		return;
	}
	else
	if ((*pplist)->next==NULL)
	{
		return;
	}
	else
	{
		//pNode n1;
		//pNode n2;
		//pNode n3;
		//n1 = *pplist;
		//n2 = n1->next;
		//n3 = n2->next;
		//while (n2)
		//{
		//	n2->next = n1;
		//	n1 = n2;
		//	n2 = n3;
		//	if (n3 != NULL)
		//	{
		//		n3 = n3->next;
		//	}
		//}
		//(*pplist)->next = NULL;
		//(*pplist) = n1;//����1


		pNode cur = NULL;
		pNode tmp = NULL;
		cur = *pplist;
		tmp = cur->next;
		pNode head = NULL;
		while (cur != NULL)
		{
			cur->next = head;
			head = cur;
			cur = tmp;
			if (tmp != NULL)
			{
				tmp = tmp->next;
			}
		}
		*pplist = head;//������
	}
}

void BubbleSort(pList plist)//����ð������
{
	
	pNode tail = NULL;
	if (plist == NULL || plist->next == NULL)
	{
		return;
	}
	tail = plist;
	while (NULL!=tail)
	{
		tail = tail->next;
	}

	pNode cur = NULL;
	while (plist != tail)
	{
		cur = plist;
		while (cur->next != tail)
		{
			if ((cur->data)>(cur->next->data))
			{
				(cur->data) ^= (cur->next->data);
				(cur->next->data) ^= (cur->data);
				(cur->data) ^= (cur->next->data);
				cur = cur->next;
			}
			else
			{
				cur = cur->next;
			}
		}
		tail = cur;
	}

}

pList pLinkNodeMerge(pList plist, pList plist2)//�ϲ��������������޵ݹ飩
{
	if (plist == NULL&&plist2 != NULL)
	{
		return plist2;
	}
	else if (plist2 == NULL&&plist != NULL)
	{
		return plist;
	}
	else if (plist2 == NULL&&plist == NULL)
	{
		return NULL;
	}
	else if (plist == plist2)
	{
		return NULL;
	}
	else
	{
		;
	}

	pList newplist = NULL;
	pNode newnode = NULL;
	pNode list1 = plist;
	pNode list2 = plist2;

	if ((list1->data) >= (list2->data))
	{
		newplist = list2;
		list2 = list2->next;

	}
	else
	{
		newplist = list1;
		list1 = list1->next;
	}
	newnode = newplist;//���ײ�

	while (list1 != NULL && list2 != NULL)
	{
		if ((list1->data) >= (list2->data))
		{
			newnode->next = list2;
			list2 = list2->next;
			newnode = newnode->next;
			
		}
		else
		{
			newnode->next = list1;
			list1 = list1->next;
			newnode = newnode->next;
		}
	}//�����ҽ��

	if (list1 == NULL&&list2 != NULL)
	{
		newnode->next = list2;
	}
	else if (list2 == NULL&&list1 != NULL)
	{
		newnode->next = list1;
	}
	else
	{
		;
	}//ʣ���

	return newplist;

}

pList pLinkNodeMerge_r(pList plist, pList plist2)//�ϲ��������������еݹ飩
{
	if (plist == NULL&&plist2 != NULL)
	{
		return plist2;
	}
	else if (plist2 == NULL&&plist != NULL)
	{
		return plist;
	}
	else if (plist2 == NULL&&plist == NULL)
	{
		return NULL;
	}
	else if (plist == plist2)
	{
		return NULL;
	}
	else
	{
		;
	}

	pList newplist = NULL;
	pNode list1 = plist;
	pNode list2 = plist2;

	if ((list1->data) >= (list2->data))
	{
		newplist = list2;
		newplist->next = pLinkNodeMerge_r(list1, list2->next);
	}
	else
	{
		newplist = list1;
		newplist->next = pLinkNodeMerge_r(list1->next, list2);
	}
	return newplist;
}

pNode pLinkFindMidNode(pList plist4)//����һ���ҵ��м���
{
	pNode list1 = NULL;
	pNode list2 = NULL;
	list1 = plist4;
	list2 = plist4;
	while (list1->next!=NULL&&list1->next->next!=NULL)
	{
		list1 = list1->next->next;
		list2 = list2->next;
	}
	return list2;
}

pNode pLinkFindLastKNode(pList plist4, int k)//����һ���ҵ�����k�����
{
	pNode list1 = NULL;
	pNode list2 = NULL;
	list1 = plist4;
	list2 = plist4;
	for (int i = 0; i < k; i++)
	{
		if (list1 == NULL)
		{
			return NULL;
		}
			list1 = list1->next;
	}
	while (list1!=NULL)
	{
		list1 = list1->next;
		list2 = list2->next;
	}
	return list2;
}

pNode IsCircle(pList plist4)//�ж��Ƿ����
{
	pNode fast = plist4;
	pNode slow = plist4;
	if (plist4 == NULL)
	{
		return NULL;
	}
	while (fast!=NULL&&fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return fast;
		}
	}
	return NULL;
}

int GetCircleLength(pNode pos3)//�󻷳���
{
	assert(pos3!=NULL);
	pNode cur = pos3;
	int len = 1;
	while (cur->next!=pos3)
	{
		len++;
		cur = cur->next;
	}
	return len;
}

pNode getCircleDoor(pList list, pNode meet)//�󻷵����,�ļ�����ԭ��ͼ
{
	assert(meet != NULL);
	if (list == NULL)
	{
		return NULL;
	}

	pNode start = list;
	while (start != meet)
	{
		meet = meet->next;
		start = start->next;
	}
	return start;
}

int CheckCross(pList plist1, pList plist2)//���������Ƿ��㽶
{
	assert(plist1 != NULL);
	assert(plist2 != NULL);
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	while (cur1->next!=NULL)
	{
		cur1 = cur1->next;
	}
	while (cur2->next!=NULL)
	{
		cur2 = cur2->next;
	}
	if (cur1 == cur2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

pNode GetCrossNode(pList plist5, pList plist6)//���㽶��
{
	if (plist5 == NULL || plist6 == NULL)
	{
		return NULL;
	}
	pNode cur1 = plist5;
	pNode cur2 = plist6;
	int count1 = 0;
	int count2 = 0;
	while (cur1!=NULL)
	{
		cur1 = cur1->next;
		count1++;
	}

	while (cur2!=NULL)
	{
		cur2 = cur2->next;
		count2++;
	}

	int dif = 0;
	if (count1 > count2)
	{
		cur1 = plist5;
		cur2 = plist6;
		dif = count1 - count2;
		while (dif--)
		{
			cur1 = cur1->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}

	else if (count1<count2)
	{
		cur1 = plist5;
		cur2 = plist6;
		dif = count2 - count1;
		while (dif--)
		{
			cur2 = cur2->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}

	else
	{
		cur1 = plist5;
		cur2 = plist6;
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
}

void TestUnionSet(pList plist1,pList plist2)//���������󽻼�
{
	if ((plist1 ==NULL)|| (plist2==NULL))
	{
		return;
	}

	printf("��������Ľ����У�");

	while (plist1!= NULL&&plist2!=NULL)
	{
		if (plist1->data < plist2->data)
		{
			plist1 = plist1->next;
		}
		else if (plist1->data > plist2->data)
		{
			plist2 = plist2->next;
		}
		else
		{
			printf("%d  ", plist1->data);
			plist1 = plist1->next;
			plist2 = plist2->next;
			
		}
	}
	printf("\n");
}



ComplexNode* BuyComplexNode(int d)//������������Ľ��
{
	ComplexNode* plist = (ComplexNode*)malloc(sizeof(ComplexNode));
	plist->data = d;
	plist->next = NULL;
	plist->random = NULL;
	return plist;
}

void PrintfComplexList(ComplexNode* plist)//��ӡ��������
{
	ComplexNode* cur = plist;
	while (cur!=NULL)
	{
		printf("%d:",cur->data);
		if (cur->random!=NULL)
			printf("(%d:)-->",cur->random->data);
		else
		{
			printf("( )-->");
		}
		cur = cur->next;
	}
	printf("over\n");
}

ComplexNode* CopyComplexList(ComplexNode* plist)//��������
{
	ComplexNode* cur = plist;//��ǰ�����������ͬ����
	ComplexNode* next = cur->next;
	while (cur!=NULL)
	{
		ComplexNode* newNode = BuyComplexNode(cur->data);
		newNode->next = next;
		cur->next = newNode;
		if (next!=NULL)
		{
			next = next->next;
		}
		cur = cur->next->next;
	}
	cur = plist;//����randomָ��
	while (cur!=NULL)
	{
		if (cur->random != NULL)
		{
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	
	ComplexNode* newList ;//����������ֿ�
	cur = plist;
	ComplexNode* cp = cur->next;
	newList = cp;
	while (cur)
	{
		cur->next = cp->next;
		if (cur->next)
		{
			cp->next = cur->next->next;
		}
		cur = cur->next;
		cp = cp->next;
	}
	return newList;
}

void TestComplexCopyList(ComplexNode* plist)//��������
{
	ComplexNode* plist1 = BuyComplexNode(5);
	ComplexNode* plist2 = BuyComplexNode(4);
	ComplexNode* plist3 = BuyComplexNode(3);
	ComplexNode* plist4 = BuyComplexNode(2);
	ComplexNode* plist5 = BuyComplexNode(1);
	plist = plist1;

	plist1->next = plist2;
	plist2->next = plist3; 
	plist3->next = plist4;
	plist4->next = plist5;

	plist1->random = plist3;
	plist2->random = plist1;
	plist3->random = NULL;
	plist4->random = plist2;
	plist5->random = plist4;

	PrintfComplexList(plist);

	ComplexNode* newlist = CopyComplexList(plist);//��ʼ����
	PrintfComplexList(newlist);

}