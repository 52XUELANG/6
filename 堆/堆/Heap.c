#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

void CreateHeap(Heap* hp, DataType* array, int size, Compare com)//创建堆
{
	if (NULL == hp)
		return;

	hp->_capacity = 0;
	hp->_size = 0;
	hp->com = com;
	//给堆申请空间
	InitHeap(hp,size);
	hp->_capacity = size;
	//将数组中的元素放到堆中
	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = array[i];
		hp->_size++;

	}

	//调整，满足堆的性质
	int root = size / 2 - 1;
	for (root; root >= 0; root--)
	{
		AdjustDown(hp,root,com);//向下调整
	}
}

void InitHeap(Heap* hp, int size)//初始化
{
	if (hp==NULL)
	{
		return;
	}
	hp->_array = (DataType*)malloc(sizeof(DataType)*size);
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}
	hp->_capacity = 5;
	hp->_size = 0;
}

void AdjustDown(Heap* hp, int root, Compare com)//向下调整,建立堆
{
	int child = root * 2 + 1;
	while (child&&child<(hp->_size))
	{
		if  (com(hp->_array[child+1], hp->_array[child]))
		{
			child++;
		}
		if  (com(hp->_array[child],hp->_array[root]))
		{
			Swap(&hp->_array[root], &hp->_array[child]);//交换
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void Swap(DataType* pData1, DataType* pData2)//交换
{
	assert(pData1);
	assert(pData2);
	DataType temp;
	temp = *pData1;
	*pData1 = *pData2;
	*pData2 = temp;
}

void InsertHeap(Heap* hp,DataType data,Compare com)//插入
{
	if (hp == NULL)
	{
		return;
	}
	CheckCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	int child = hp->_size-1;
	int parent = (child-1)/2;
	AdjustUp(hp, child, parent, com);
}

void AdjustUp(Heap* hp, int child, int parent, Compare com)//向上调整
{
	while (child > 0)
	{
		if (com(hp->_array[child], hp->_array[parent]))
		{
			Swap(&(hp->_array[parent]), &(hp->_array[child]));
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			return;
		}
	}
}

void CheckCapacity(Heap* hp)//检测容量
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		int newCapacity = hp->_capacity * 2;
		DataType* newHeap = (DataType*)malloc(newCapacity);
		if (newHeap == NULL)
		{
			assert(0);
			return;
		}

		hp->_capacity *= 2;

		for  (int i = 0;  i < hp->_size;  i++)
		{
			newHeap[i] = hp->_array[i];
		}
		free(hp->_array);
		hp->_array = newHeap;
	}
}

void DeleteHeap(Heap* hp,Compare com)//删除
{
	if (EmptyHeap(hp))
	{
		return;
	}
	hp->_array[0] = hp->_array[hp->_size - 1];
	(hp->_size)--;
	AdjustDown(hp, 0, com);
}

int EmptyHeap(Heap* hp)//判空
{
	assert(hp);
	return 0 == hp->_size;
}

int Less(DataType data1, DataType data2)
{
	return (data1 < data2);
}

int Bigger(DataType data1, DataType data2)
{
	return data1>data2;
}

DataType TopHead(Heap* hp)//获取堆顶元素
{
	assert(hp);
	return hp->_array[0];
}





void InitPQueue(PQueue* Pq)//优先级队列初始化
{
	InitHeap(&(Pq->_hp),5);
}

void PushPQueue(PQueue* Pq, DataType data, Compare com)//插入
{
	InsertHeap(&(Pq->_hp), data, com);
}

void PopPQueue(PQueue* Pq, Compare com)//出队列
{
	DeleteHeap(&(Pq->_hp), com);
}

int SizePQueue(PQueue* Pq)//查询大小
{
	return Pq->_hp._size;
}

int EmptyPQueue(PQueue* Pq)//判空
{
	return EmptyHeap(&(Pq->_hp));//直接判断优先级队列里的底层结构——堆是否为空
}

DataType TopPQueue(PQueue* Pq)
{
	return TopHead(&(Pq->_hp));
}





void HeapSort(Heap* hp,Compare com)//堆排序
{
	if (NULL == hp)
		return;
	int temp = 0;
	int size = hp->_size;
	while (size > 0)
	{
		Swap(&hp->_array[0], &hp->_array[size - 1]);
		size--;
		int parent = 0;
		int child = parent * 2 + 1;
		while (child<size)
		{
			if ((child +1)<size&&com(hp->_array[child + 1], hp->_array[child]))
			{
				child++;
			}
			if (com(hp->_array[child], hp->_array[parent]))
			{
				Swap(&hp->_array[child], &hp->_array[parent]);
			}
			parent = child;
			child = parent * 2 + 1;
		}
	}
	
	
}