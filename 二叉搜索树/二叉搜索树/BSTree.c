#define _CRT_SECURE_NO_WARNINGS
#include"BSTree.h"
void InitBST(pBSTreeNode* pRoot)//初始化
{
	assert(pRoot);
	*pRoot = NULL;
}

void InsertBST(pBSTreeNode* pRoot, DataType data)//插入
{
	assert(pRoot);
	if (NULL == *pRoot)//空树
	{
		*pRoot = BuyBSTreeNode(data);
		return;
	}

	//非空树，查找待插入节点的位置
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
	//插入结点
	if (data < pParent->_data)
	{
		pParent->_pLeft = pCur;
	}
	else
	{
		pParent->_pRight = pCur;
	}
}

pBSTreeNode BuyBSTreeNode(DataType data)//创建结点
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

int FindBSTreeNode(pBSTreeNode pRoot, DataType data)//查找
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

void DestoryBSTree(pBSTreeNode* pRoot)//销毁
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

void DeleteBSTree(pBSTreeNode* pRoot, DataType data)//删除结点
{
	assert(pRoot);
	pBSTreeNode pCur = *pRoot;
	pBSTreeNode pParent = NULL;//保存双亲结点
	//找待删除的结点的位置
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


	if (pCur == NULL)//找的结点不在树中
	{
		return;
	}


	if (NULL == pCur->_pLeft)//只有右子树
	{
		if (pCur == *pRoot)
		{
			*pRoot = pCur->_pRight;
		}
		else if (pCur == pParent->_pLeft)
		{
			pParent->_pLeft = pCur->_pRight;//待删除节点是其双亲的左孩子
		}
		else
		{
			pParent->_pRight = pCur->_pRight;//待删除节点是其双亲的右孩子
		}
	}

	else if (NULL == pCur->_pRight)//只有左子树
	{
		if (pCur == *pRoot)//待删除节点为根节点
		{
			//直接删除
			*pRoot = pCur->_pLeft;
		}
		else
		{
			if (pCur == pParent->_pLeft)
			{
				pParent->_pLeft = pCur->_pLeft;//待删除节点是其双亲的左孩子
			}
			else
			{
				pParent->_pRight = pCur->_pLeft;//待删除节点是其双亲的右孩子
			}
		}
	}
	else
	{
		//待删除节点左右孩子都存在,在其右子树中找最小的(最左边)节点或在左子树中找最大的(最右边)节点
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



int FindBSTreeNodeREC(pBSTreeNode pRoot, DataType data)//递归方法
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

void InsertBSTREC(pBSTreeNode* pRoot, DataType data)//插入递归
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

void DeleteBSTreeREC(pBSTreeNode* pRoot, DataType data)//删除结点递归
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
