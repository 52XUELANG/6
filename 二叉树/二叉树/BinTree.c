#define _CRT_SECURE_NO_WARNINGS
#include"BinTree.h"


void TestBinTree()//测试
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
	pBinTreeNode pNewBinTreeNode =  BinTreeFind(pRoot, 'D');//查找
	printf("存在%c\n",pNewBinTreeNode->_data);
	int count = BinTreeHeight(pRoot);
	printf("%d\n",count);


	DetoryBinTree(&pRoot);
	DetoryBinTree(&pRoot2);
	PreOrder(pRoot);
	printf("\n");
	PreOrder(pRoot2);
	printf("\n");
}


pBinTreeNode BuyBinTreeBinTreeNode(BinTreeDataType data)//创建结点
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


void CreateBinTree(pBinTreeNode* pRoot, BinTreeDataType array[], int size, int* index/*索引*/, BinTreeDataType invalid/*无效值*/)//创建二叉树
{
	assert(pRoot);
	assert(index);//确保索引存在
	if ((*index) < size && invalid!=array[*index])//先保证在数据边界内
	{
		*pRoot = BuyBinTreeBinTreeNode(array[*index]);//创建根节点
		++(*index)/*下一个的索引*/;
		CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);//左子树创建
		++(*index)/*下一个的索引*/;
		CreateBinTree(&(*pRoot)->_pRight, array, size, index, invalid);//右子树创建
	}
}


pBinTreeNode CopyBinTree(pBinTreeNode pRoot)//拷贝
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


void PreOrder(pBinTreeNode pRoot)//前序
{
	if (pRoot)
	{
		printf("%c  ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}


void InOrder(pBinTreeNode pRoot)//中序
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c  ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
	return;
}


void PostOrder(pBinTreeNode pRoot)//后序
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c  ", pRoot->_data);
	}
}


void DetoryBinTree(pBinTreeNode* pRoot)//销毁,后序
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


void LevelOrder(pBinTreeNode pRoot)//层序遍历
{
	if (pRoot)
	{
		return;
	}

}


void MirrorBinTree(pBinTreeNode pRoot)//镜像
{
	if (pRoot)
	{
		return;
	}

}


int BinTreeSize(pBinTreeNode pRoot)//结点个数
{
	if (pRoot == NULL)
		return 0;
	return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight) + 1;
}


int BinTreeLeafSize(pBinTreeNode pRoot)//叶子结点个数
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


int BinTreeLevelKSize(pBinTreeNode pRoot, int k)//第k层的结点数
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


pBinTreeNode BinTreeFind(pBinTreeNode pRoot, BinTreeDataType thing)//查找
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


int BinTreeHeight(pBinTreeNode pRoot)//树高度
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int left_height = BinTreeHeight(pRoot->_pLeft);
	int right_height = BinTreeHeight(pRoot->_pRight);
	return left_height > right_height ? left_height+1 : right_height+1;
}




