#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
#include"Stack.h"
int main()
{
	int array[] = {9,8,7,6,5,4,3,2,1,11,23,64,98,79,35,47,52,86};
	int size = sizeof(array) / sizeof(array[0]);
	//InsertSort(array,size);
	//InsertSortBetter(array, size);
	//ShellSort(array, size);
	//SelectSort(array, size);
	//SelectSort2(array, size);
	//HeapSort(array, size);
	//QuickSortNor(array,size);//øÏ≈≈
	//Merge(array, size); 
	//MergeNor(array, size);
	//CountSort(array, size);
	RadixSort(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ",array[i]);
	}
	system("pause");
	return 0;
}