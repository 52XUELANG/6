#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

void CreateHeap(Heap* hp, DataType* array, int size, Compare com)//������
{
	if (NULL == hp)
		return;

	hp->_capacity = 0;
	hp->_size = 0;
	hp->com = com;
	//��������ռ�
	InitHeap(hp,size);
	hp->_capacity = size;
	//�������е�Ԫ�طŵ�����
	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = array[i];
		hp->_size++;

	}

	//����������ѵ�����
	int root = size / 2 - 1;
	for (root; root >= 0; root--)
	{
		AdjustDown(hp,root,com);//���µ���
	}
}

void InitHeap(Heap* hp, int size)//��ʼ��
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

void AdjustDown(Heap* hp, int root, Compare com)//���µ���,������
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
			Swap(&hp->_array[root], &hp->_array[child]);//����
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void Swap(DataType* pData1, DataType* pData2)//����
{
	assert(pData1);
	assert(pData2);
	DataType temp;
	temp = *pData1;
	*pData1 = *pData2;
	*pData2 = temp;
}

void InsertHeap(Heap* hp,DataType data,Compare com)//����
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

void AdjustUp(Heap* hp, int child, int parent, Compare com)//���ϵ���
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

void CheckCapacity(Heap* hp)//�������
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

void DeleteHeap(Heap* hp,Compare com)//ɾ��
{
	if (EmptyHeap(hp))
	{
		return;
	}
	hp->_array[0] = hp->_array[hp->_size - 1];
	(hp->_size)--;
	AdjustDown(hp, 0, com);
}

int EmptyHeap(Heap* hp)//�п�
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

DataType TopHead(Heap* hp)//��ȡ�Ѷ�Ԫ��
{
	assert(hp);
	return hp->_array[0];
}





void InitPQueue(PQueue* Pq)//���ȼ����г�ʼ��
{
	InitHeap(&(Pq->_hp),5);
}

void PushPQueue(PQueue* Pq, DataType data, Compare com)//����
{
	InsertHeap(&(Pq->_hp), data, com);
}

void PopPQueue(PQueue* Pq, Compare com)//������
{
	DeleteHeap(&(Pq->_hp), com);
}

int SizePQueue(PQueue* Pq)//��ѯ��С
{
	return Pq->_hp._size;
}

int EmptyPQueue(PQueue* Pq)//�п�
{
	return EmptyHeap(&(Pq->_hp));//ֱ���ж����ȼ�������ĵײ�ṹ�������Ƿ�Ϊ��
}

DataType TopPQueue(PQueue* Pq)
{
	return TopHead(&(Pq->_hp));
}





void HeapSort(Heap* hp,Compare com)//������
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