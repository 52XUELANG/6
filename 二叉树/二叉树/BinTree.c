#define _CRT_SECURE_NO_WARNINGS
#include"BinTree.h"


void TestBinTree()//����
{
	char* str = "ABD###CE##F";
	pBinTreeNode pRoot = NULL;
	int index = 0;
	pBinTreeNode pRoot2 = NULL;
	CreateBinTree(&pRoot, str, strlen(str), &index, '#');
	pRoot2 = CopyBinTree(pRoot);
	PreOrder(pRoot);
	printf("\n");
	PreOrder(pRoot2);
	printf("\n");
	InOrder(pRoot);
	printf("\n");
	InOrder(pRoot2);
	printf("\n");
	PostOrder(pRoot);
	printf("\n");
	PostOrder(pRoot2);
	printf("\n");
	int size = BinTreeSize(pRoot);
	printf("%d\n",size);
	int leaf_size = BinTreeLeafSize(pRoot);
	printf("%d\n", leaf_size);
	int k = 0;
	scanf("%d",&k);
	int level_k_size = BinTreeLevelKSize(pRoot, k);
	printf("%d\n", level_k_size);
	pBinTreeNode pNewBinTreeNode =  BinTreeFind(pRoot, 'D');//����
	printf("����%c\n",pNewBinTreeNode->_data);
	int count = BinTreeHeight(pRoot);
	printf("%d\n",count);


	DetoryBinTree(&pRoot);
	DetoryBinTree(&pRoot2);
	PreOrder(pRoot);
	printf("\n");
	PreOrder(pRoot2);
	printf("\n");
}


pBinTreeNode BuyBinTreeBinTreeNode(BinTreeDataType data)//�������
{
	pBinTreeNode pNewBinTreeNode = (pBinTreeNode)malloc(sizeof(BinTreeNode));
	if (NULL == pNewBinTreeNode)
	{
		assert(0);
		return NULL;
	}
	pNewBinTreeNode->_data = data;
	pNewBinTreeNode->_pLeft = NULL;
	pNewBinTreeNode->_pRight = NULL;
	return pNewBinTreeNode;
}


void CreateBinTree(pBinTreeNode* pRoot, BinTreeDataType array[], int size, int* index/*����*/, BinTreeDataType invalid/*��Чֵ*/)//����������
{
	assert(pRoot);
	assert(index);//ȷ����������
	if ((*index) < size && invalid!=array[*index])//�ȱ�֤�����ݱ߽���
	{
		*pRoot = BuyBinTreeBinTreeNode(array[*index]);//�������ڵ�
		++(*index)/*��һ��������*/;
		CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);//����������
		++(*index)/*��һ��������*/;
		CreateBinTree(&(*pRoot)->_pRight, array, size, index, invalid);//����������
	}
}


pBinTreeNode CopyBinTree(pBinTreeNode pRoot)//����
{
	assert(pRoot);
	pBinTreeNode pNewBinTreeNode = NULL;
	pNewBinTreeNode = BuyBinTreeBinTreeNode(pRoot->_data);
	if (pRoot->_pLeft)
	pNewBinTreeNode->_pLeft = CopyBinTree(pRoot->_pLeft);
	if (pRoot->_pRight)
	pNewBinTreeNode->_pRight = CopyBinTree(pRoot->_pRight);
	return pNewBinTreeNode;
}


void PreOrder(pBinTreeNode pRoot)//ǰ��
{
	if (pRoot)
	{
		printf("%c  ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}


void InOrder(pBinTreeNode pRoot)//����
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c  ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
	return;
}


void PostOrder(pBinTreeNode pRoot)//����
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c  ", pRoot->_data);
	}
}


void DetoryBinTree(pBinTreeNode* pRoot)//����,����
{
	assert(pRoot);
	if (*pRoot)
	{
		DetoryBinTree(&(*pRoot)->_pLeft);
		DetoryBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}


void LevelOrder(pBinTreeNode pRoot)//�������
{
	if (pRoot)
	{
		return;
	}

}


void MirrorBinTree(pBinTreeNode pRoot)//����
{
	if (pRoot)
	{
		return;
	}

}


int BinTreeSize(pBinTreeNode pRoot)//������
{
	if (pRoot == NULL)
		return 0;
	return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight) + 1;
}


int BinTreeLeafSize(pBinTreeNode pRoot)//Ҷ�ӽ�����
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
	{
		return 1;
	}
	return BinTreeLeafSize(pRoot->_pLeft) + BinTreeLeafSize(pRoot->_pRight);
}


int BinTreeLevelKSize(pBinTreeNode pRoot, int k)//��k��Ľ����
{
	if (pRoot == NULL)
	{
		return 0;
	}
	if (1 == k)
	{
		return 1;
	}
	return BinTreeLevelKSize(pRoot->_pLeft, k - 1) + BinTreeLevelKSize(pRoot->_pRight, k - 1);
}


pBinTreeNode BinTreeFind(pBinTreeNode pRoot, BinTreeDataType thing)//����
{
	if (pRoot == NULL)
	{
		return NULL;
	}
	pBinTreeNode ret = NULL;

	if (pRoot->_data == thing)
	{
		return pRoot;
	}

	ret = BinTreeFind(pRoot->_pLeft, thing);
	if (ret)
	{
		return ret;
	}

	ret = BinTreeFind(pRoot->_pRight, thing);
	if (ret)
	{
		return ret;
	}
	return NULL;
}


int BinTreeHeight(pBinTreeNode pRoot)//���߶�
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int left_height = BinTreeHeight(pRoot->_pLeft);
	int right_height = BinTreeHeight(pRoot->_pRight);
	return left_height > right_height ? left_height+1 : right_height+1;
}




