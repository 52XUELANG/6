#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

int main()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;
	int choice = 0;
	scanf("%d",&choice);//1Ð¡¶Ñ£¬½µÐò£»2´ó¶Ñ£¬ÉýÐò
	Compare com = Less;
	switch (choice)
	{
	case 1:com = Less; break;
	case 0:com = Bigger; break;
	default:
		break;
	}
	CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]), com);
	InsertHeap(&hp, 5, com);
	for (int i = 0; i < hp._size; i++)
		printf("%d ",hp._array[i]);
	printf("\n");
	HeapSort(&hp,Less);//¶ÑÅÅÐò
	for (int i = 0; i < hp._size; i++)
		printf("%d ", hp._array[i]);

	/*PQueue Pq;
	InitPQueue(&Pq);
	PushPQueue(&Pq, 3,Bigger);
	PushPQueue(&Pq, 1, Bigger);
	PushPQueue(&Pq, 2, Bigger);
	PushPQueue(&Pq, 5, Bigger);
	PushPQueue(&Pq, 4, Bigger);
	printf("size = %d\n",SizePQueue(&Pq));
	printf("top = %d\n", TopPQueue(&Pq));
	PopPQueue(&Pq,Bigger);
	printf("size = %d\n",SizePQueue(&Pq));
	for (int i = 0; i < Pq._hp._size;i++)
	printf("%d  ",Pq._hp._array[i]);*/
	system("pause");
	return 0;
}