#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include<assert.h>
#include<string.h>

//void InitList(pList* pplist)//初始化
//{
//	assert(pplist != NULL);//判空
//	*pplist = NULL;
//}
pNode BuyNode(int d)//创建结点,返回结点地址
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;
	return newNode;//返回创建结点的地址
}

void PushBack(pList* pplist, int d)
{
	assert(NULL != pplist);
	if (*pplist == NULL)//空链表
	{
		pNode newNode = BuyNode(d);//创建结点
		*pplist = newNode;//创建结点的挂钩链接
	}
	else//非空链表
	{
		pNode cur = *pplist;//定义指针指向链表头
		while (NULL != cur->next)
		{
			cur = cur->next;
		}//查找最后一个结点
		pNode newNode = BuyNode(d);
		cur->next = newNode;//结点挂钩
	}
}

void PrintList(pList plist)
{
	pNode cur = plist;
	while (NULL != cur)
	{
		printf("%d->",cur->data);//打印当前数据
		cur = cur->next;//后移
	}
	printf("over\n");
}

void DestroyList(pList* pplist)//销毁
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

int GetListLength(pList plist)//求链表长度
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

void PopBack(pList* pplist)//尾部删除
{
	assert(NULL != pplist);
	if (*pplist == NULL)//空链表
	{
		return;
	}
	else
	if ((*pplist)->next == NULL)//一个结点
	{
		free(*pplist);
		*pplist = NULL;
	}
	else//一个以上的结点
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

void PushFront(pList* pplist, int d)//头插入
{
	assert(pplist != NULL);
		pNode newNode = BuyNode(d);
		newNode->next = *pplist;
		*pplist = newNode;
}

void PopFront(pList* pplist)//头删除
{
	assert(pplist != NULL);
	if (*pplist == NULL)//空链表
	{
		return;
	}
	else
	if ((*pplist)->next == NULL)//一个结点
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

pNode Find(pList plist, int d)//查找
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

void Insert(pList* pplist, pNode pos, int d)//指定位置插入
{
	assert(pplist != NULL); 
	assert(*pplist != NULL);//空链表
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
		printf("没有所要的结点");
		return;
	}
}

void Erase(pList* pplist, pNode pos)//指定位置删除
{
	assert(pplist != NULL);
	assert(pos != NULL);
	pNode del = pos;
	if (*pplist == NULL)//空链表
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
		printf("没有所要的结点");
		return;
	}

}

void Remove(pList* pplist, int d)//删除指定元素的结点，可以利用查找和删除函数组合
{
	
	assert(pplist != NULL);
	pNode cur = NULL;
	cur = *pplist;
	pNode del = NULL;
	while (cur!=NULL)
	{
		if (cur->data == d)
		{
			if (*pplist == cur)//第一个节点
			{
				*pplist = (*pplist)->next;
				free(cur);
				cur = NULL;
			}
			else//非第一个结点
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

void RemoveAll(pList* pplist, int d)//删除指定所有元素
{
	assert(pplist != NULL);
	pNode cur = NULL;
	cur = *pplist;
	pNode del = NULL;
	while (cur != NULL)
	{
		if (cur->data == d)
		{
			if (*pplist == cur)//第一个节点
			{
				*pplist = (*pplist)->next;
				free(cur);
				cur = *pplist;
			}
			else//非第一个结点
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

void TestPrintTailToHead(pList plist)//逆序打印
{
	//if (plist == NULL)
	//{
	//	return;
	//}
	//else
	//{
	//	TestPrintTailToHead(plist->next);//递归方法，大化小，从尾部开始
	//	printf("%d->",plist->data);
	//}
	


	if (plist == NULL)//递归方法
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
			while (cur->next != tail )//tail初始化为NULL，第一次循环也可跳出
			{
				cur = cur->next;
			}
			printf("%d->", cur->data);
			tail = cur;
		}
	}
}

void EraseNotTail(pNode pos)//删除无头单链表的非尾结点
{
	//替换删除法
	assert(pos != NULL);
	assert(pos->next != NULL);//判断尾结点
	pos->data = pos->next->data;
	pos->next = pos->next->next;
	free(pos->next);
	pos->next = NULL;
}

void InsertNode(pNode pos,int d)//无头结点之前插入一个结点
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

void JosephusCycle(pList* pplist,int k)//约瑟夫环
{
	pNode cur = *pplist;
	while (cur != cur->next)
	{
		pNode del = NULL;
		for (int i = 1; i < k; i++)
		{
			cur = cur->next;
		}
		printf("删除:%d\n",cur->data);
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = cur->next->next;
		free(del);
		del = NULL;
	}
	printf("幸存者：%d\n",cur->data);
}

void ReverseList(pList* pplist)//反转单链表
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
		//(*pplist) = n1;//方法1


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
		*pplist = head;//方法二
	}
}

void BubbleSort(pList plist)//链表冒泡排序
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

pList pLinkNodeMerge(pList plist, pList plist2)//合并两个有序链表（无递归）
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
	newnode = newplist;//挂首层

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
	}//继续挂结点

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
	}//剩余的

	return newplist;

}

pList pLinkNodeMerge_r(pList plist, pList plist2)//合并两个有序链表（有递归）
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

pNode pLinkFindMidNode(pList plist4)//遍历一遍找到中间结点
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

pNode pLinkFindLastKNode(pList plist4, int k)//遍历一次找倒数第k个结点
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

pNode IsCircle(pList plist4)//判断是否带环
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

int GetCircleLength(pNode pos3)//求环长度
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

pNode getCircleDoor(pList list, pNode meet)//求环的入口,文件中有原理图
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

int CheckCross(pList plist1, pList plist2)//两条链表是否香蕉
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

pNode GetCrossNode(pList plist5, pList plist6)//求香蕉点
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

void TestUnionSet(pList plist1,pList plist2)//有序链表求交集
{
	if ((plist1 ==NULL)|| (plist2==NULL))
	{
		return;
	}

	printf("两条链表的交集有：");

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



ComplexNode* BuyComplexNode(int d)//创建复杂链表的结点
{
	ComplexNode* plist = (ComplexNode*)malloc(sizeof(ComplexNode));
	plist->data = d;
	plist->next = NULL;
	plist->random = NULL;
	return plist;
}

void PrintfComplexList(ComplexNode* plist)//打印复杂链表
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

ComplexNode* CopyComplexList(ComplexNode* plist)//拷贝函数
{
	ComplexNode* cur = plist;//当前结点后面插入相同数据
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
	cur = plist;//调整random指针
	while (cur!=NULL)
	{
		if (cur->random != NULL)
		{
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	
	ComplexNode* newList ;//将两个链表分开
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

void TestComplexCopyList(ComplexNode* plist)//复杂链表
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

	ComplexNode* newlist = CopyComplexList(plist);//开始拷贝
	PrintfComplexList(newlist);

}