#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
#include<assert.h>
#include<string.h>

void test2(pList plist)
{
	TestPrintTailToHead(plist);
	printf("\n");
	pNode pos = NULL;
	pos = Find(plist, 4);
	EraseNotTail(pos); //ɾ����ͷ������ķ�β���
	PrintList(plist);//��ӡ
	pos = Find(plist, 5);
	InsertNode(pos,6);//��ͷ���֮ǰ����һ�����
	PrintList(plist);//��ӡ
	//for (int i = 1; i < 10; i++)
	//{
	//	PushBack(&plist, i);
	//}
	//Find(plist,9)->next=plist;
	//JosephusCycle(&plist,3);//Լɪ��
	ReverseList(&plist);//��ת������
	PrintList(plist);//��ӡ
	BubbleSort(plist);//����ð������
	PrintList(plist);//��ӡ
	Node* plist2 = NULL;
	PushBack(&plist2, 3); 
	PushBack(&plist2, 4);
	PushBack(&plist2, 7);
	//pList plist3 = NULL;
	//plist3 = pLinkNodeMerge(plist, plist2);//�ϲ��������������޵ݹ飩
	//PrintList(plist3);//��ӡ
	pList plist4 = NULL;
	plist4 = pLinkNodeMerge_r(plist, plist2);//�ϲ��������������еݹ飩
	PrintList(plist4);//��ӡ
	pNode pos2 = NULL;
	pos2 = pLinkFindMidNode(plist4);//����һ���ҵ��м���
	printf("%d\n", pos2->data);
	int k = 0;
	scanf("%d",&k);
	pNode pos5 = NULL;
	pos5 = pLinkFindLastKNode(plist4, k);//����һ���ҵ�����k�����
	if (pos5 != NULL)
	{
		printf("%d\n", pos5->data);
	}
	Find(plist4, 7)->next = Find(plist4, 4);
	pNode pos3 =  IsCircle(plist4);//�ж��Ƿ����
	if (pos3 == NULL)
	{
		printf("������\n");
	}
	else
	{
		printf("����,������Ϊ%d\n",pos3->data);
	}
	int len = GetCircleLength(pos3);//�󻷳���
	printf("%d\n",len);

	pNode pos7 = getCircleDoor(plist4, pos3);

	printf("���Ϊ%d\n",pos7->data);



	Node* plist5 = NULL;
	PushBack(&plist5, 1);//β���������
	PushBack(&plist5, 2);
	PushBack(&plist5, 3);
	PushBack(&plist5, 4);
	PushBack(&plist5, 5);
	PushBack(&plist5, 6);
	PushBack(&plist5, 7);
	Node* plist6 = NULL;
	PushBack(&plist6, 8);//β���������
	PushBack(&plist6, 9);
	PushBack(&plist6, 10);
	PushBack(&plist6, 11);
	PushBack(&plist6, 12);
	PushBack(&plist6, 13);
	PushBack(&plist6, 14);
	Find(plist6, 14)->next = Find(plist5, 5);
	int ans = CheckCross(plist5,plist6);
	if (ans)
	{
		printf("�㽶\n");
		pNode pos = GetCrossNode(plist5, plist6);//���㽶��
		printf("����ֵΪ%d\n",pos->data);
	}
	else
	{
		printf("���㽶\n");
	}
	PrintList(plist5);//��ӡ
	PrintList(plist6);//��ӡ


	Node* plist7 = NULL;
	PushBack(&plist7, 1);//β���������
	PushBack(&plist7, 2);
	PushBack(&plist7, 3);
	PushBack(&plist7, 4);
	PushBack(&plist7, 5);
	PushBack(&plist7, 6);
	PushBack(&plist7, 7);
	Node* plist8 = NULL;
	PushBack(&plist8, 3);//β���������
	PushBack(&plist8, 4);
	PushBack(&plist8, 5);
	PushBack(&plist8, 7);
	PushBack(&plist8, 8);
	PushBack(&plist8, 9);
	PushBack(&plist8, 10);
	TestUnionSet(plist7, plist8);//���������󽻼�


	ComplexNode* plist9 = NULL;

	TestComplexCopyList(plist9);//��������
}

void test()
{
	Node* plist = NULL;//����ṹ��ָ������,������ʱ��ʼ��ΪNULL�����Բ����ٳ�ʼ��
	//InitList(&plist);//��ʼ������
	PushBack(&plist,1);//β���������
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);
	PrintList(plist);//��ӡ
	printf("%d\n", GetListLength(plist));//�鳤��
	PopBack(&plist);//β��ɾ��
	PrintList(plist);//��ӡ
	PushFront(&plist,5);//ͷ��
	PrintList(plist);//��ӡ
	PopFront(&plist);//ͷɾ
	PrintList(plist);//��ӡ
	pNode pos = NULL;
	pos = Find(plist,3);//����
	printf("%d\n",pos->data);
	Insert(&plist,pos,5);//ָ��λ�ò���
	PrintList(plist);//��ӡ
	Erase(&plist,pos);//ָ��λ��ɾ��
	PrintList(plist);//��ӡ
	Remove(&plist, 5);//ָ��Ԫ��ɾ��
	PrintList(plist);//��ӡ
	PushFront(&plist, 6);//ͷ��
	PushFront(&plist, 6);//ͷ��
	PushFront(&plist, 6);//ͷ��
	PushBack(&plist, 6);
	PushBack(&plist, 6);
	PrintList(plist);//��ӡ
	RemoveAll(&plist, 6);//ɾ��ָ������Ԫ��
	PrintList(plist);//��ӡ
	test2(plist);
	//DestroyList(&plist);//��������
}



int main()
{
	
	test();
	system("pause");
	return 0;
}