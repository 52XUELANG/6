#define _CRT_SECURE_NO_WARNINGS
#include"BSTree.h"
void InitBST(pBSTreeNode* pRoot)//��ʼ��
{
	assert(pRoot);
	*pRoot = NULL;
}

void InsertBST(pBSTreeNode* pRoot, DataType data)//����
{
	assert(pRoot);
	if (NULL == *pRoot)//����
	{
		*pRoot = BuyBSTreeNode(data);
		return;
	}

	//�ǿ��������Ҵ�����ڵ��λ��
	BSTreeNode* pCur = *pRoot;
	BSTreeNode* pParent = NULL;
	while (pCur)
	{
		if (data < pCur->_data)
		{
			pParent = pCur;
			pCur = pCur->_pLeft;
		}
		else if (data>pCur->_data)
		{
			pParent = pCur;
			pCur = pCur->_pRight;
		}
		else
		{
			return;
		}
	}


	pCur = BuyBSTreeNode(data);
	//������
	if (data < pParent->_data)
	{
		pParent->_pLeft = pCur;
	}
	else
	{
		pParent->_pRight = pCur;
	}
}

pBSTreeNode BuyBSTreeNode(DataType data)//�������
{
	BSTreeNode* pNewNode = (pBSTreeNode)malloc(sizeof(BSTreeNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}

int FindBSTreeNode(pBSTreeNode pRoot, DataType data)//����
{
	pBSTreeNode pCur = pRoot;
	while (pCur)
	{
		if (data == pCur->_data)
		{
			return 1;
		}
		else if (data < pCur->_data)
		{
			pCur = pCur->_pLeft;
		}
		else
		{
			pCur = pCur->_pRight;
		}
	}

	return 0;
}

void PreOrder(pBSTreeNode pRoot)
{
	if (pRoot)
	{
		PreOrder(pRoot->_pLeft);
		printf("%d ",pRoot->_data);
		PreOrder(pRoot->_pRight);
	}
}

void DestoryBSTree(pBSTreeNode* pRoot)//����
{
	assert(pRoot);
	if (*pRoot)
	{
		DestoryBSTree(&(*pRoot)->_pLeft);
		DestoryBSTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

void DeleteBSTree(pBSTreeNode* pRoot, DataType data)//ɾ�����
{
	assert(pRoot);
	pBSTreeNode pCur = *pRoot;
	pBSTreeNode pParent = NULL;//����˫�׽��
	//�Ҵ�ɾ���Ľ���λ��
	while (pCur)
	{
		if (data == pCur->_data)
		{
			break;
		}
		else if (data<pCur->_data)
		{
			pParent = pCur;
			pCur = pCur->_pLeft;
		}
		else
		{
			pParent = pCur;
			pCur = pCur->_pRight;
		}
	}


	if (pCur == NULL)//�ҵĽ�㲻������
	{
		return;
	}


	if (NULL == pCur->_pLeft)//ֻ��������
	{
		if (pCur == *pRoot)
		{
			*pRoot = pCur->_pRight;
		}
		else if (pCur == pParent->_pLeft)
		{
			pParent->_pLeft = pCur->_pRight;//��ɾ���ڵ�����˫�׵�����
		}
		else
		{
			pParent->_pRight = pCur->_pRight;//��ɾ���ڵ�����˫�׵��Һ���
		}
	}

	else if (NULL == pCur->_pRight)//ֻ��������
	{
		if (pCur == *pRoot)//��ɾ���ڵ�Ϊ���ڵ�
		{
			//ֱ��ɾ��
			*pRoot = pCur->_pLeft;
		}
		else
		{
			if (pCur == pParent->_pLeft)
			{
				pParent->_pLeft = pCur->_pLeft;//��ɾ���ڵ�����˫�׵�����
			}
			else
			{
				pParent->_pRight = pCur->_pLeft;//��ɾ���ڵ�����˫�׵��Һ���
			}
		}
	}
	else
	{
		//��ɾ���ڵ����Һ��Ӷ�����,����������������С��(�����)�ڵ������������������(���ұ�)�ڵ�
		pBSTreeNode pDel = pCur->_pRight;
		pParent = pCur;
		while (pDel->_pLeft)
		{
			pParent = pDel;
			pDel = pDel->_pLeft;
		}
		pCur->_data  = pDel->_data;
		if (pDel == pParent->_pLeft)
		{
			pParent->_pLeft = pDel->_pRight;
		}
		else
		{
			pParent->_pRight = pDel->_pRight;
		}
		pCur = pDel;
	}
	free(pCur);
}



int FindBSTreeNodeREC(pBSTreeNode pRoot, DataType data)//�ݹ鷽��
{
	if (pRoot)
	{
		return 0;
	}
	if (data == pRoot->_data)
	{
		return 1;
	}
	else if (data < pRoot->_data)
	{
		return FindBSTreeNodeREC(pRoot->_pLeft, data);
	}
	else
	{
		return FindBSTreeNodeREC(pRoot->_pRight, data);

	}
}

void InsertBSTREC(pBSTreeNode* pRoot, DataType data)//����ݹ�
{
	if (*pRoot==NULL)
	{
		*pRoot = BuyBSTreeNode(data);
	}
	else
	{
		if (data < (*pRoot)->_data)
		{
			InsertBSTREC(&(*pRoot)->_pLeft, data);
		}
		else if (data>(*pRoot)->_data)
		{
			InsertBSTREC(&(*pRoot)->_pRight, data);
		}
		else
		{
			return;
		}
	}
}

void DeleteBSTreeREC(pBSTreeNode* pRoot, DataType data)//ɾ�����ݹ�
{
	if (*pRoot)
		return;
	if (data < (*pRoot)->_data)
	{
		DeleteBSTreeREC(&(*pRoot)->_pLeft, data);
	}
	else if (data>(*pRoot)->_data)
	{
		DeleteBSTreeREC(&(*pRoot)->_pRight, data);
	}
	else
	{
		pBSTreeNode pDel = *pRoot;
		if (pDel->_pLeft == NULL)
		{
			*pRoot = pDel->_pRight;
			free(pDel);
		}
		else if (pDel->_pRight == NULL)
		{
			*pRoot = pDel->_pLeft;
			free(pDel);
		}
		else
		{
			pBSTreeNode pDel = (*pRoot)->_pRight;
			while (pDel->_pLeft)
			{
				pDel = pDel->_pLeft;
			}
			(*pRoot)->_data = pDel->_data;
			DeleteBSTree(&(*pRoot)->_pRight, pDel->_data);
		}
	}
}
