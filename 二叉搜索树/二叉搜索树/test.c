#define _CRT_SECURE_NO_WARNINGS
#include"BSTree.h"

int main()
{
	int a[] = { 5,3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTreeNode* pRoot;
	InitBST(&pRoot);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		InsertBSTREC(&pRoot, a[i]);
	}
	printf("\n");
	PreOrder(pRoot);
	printf("\n");
	DeleteBSTreeREC(&pRoot, 7);//É¾³ý½áµã
	PreOrder(pRoot);
	DestoryBSTree(&pRoot);//Ïú»Ù
	system("pause");
	return 0;
}