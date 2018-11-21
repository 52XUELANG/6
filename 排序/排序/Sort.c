#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
#include"Stack.h"

void InsertSort(int* array, int size)//插入排序
{
	for (int i = 1; i < size; i++)
	{
		int temp = array[i];
		int end = i-1;
		while (end >= 0 && temp < array[end])
		{
			array[end+1] = array[end];
			end--;
		}
			array[end+1] = temp;
	}
}
void InsertSortBetter(int* array, int size)//用二分查找优化插入排序
{
	for (int i = 1; i < size; i++)
	{
		int temp = array[i];
		int end = i - 1;
		int begin = 0;
		while (begin <= end)
		{
			int mid = end + (begin - end) / 2;
			if (temp >= array[mid])
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		end = i - 1;
		while (end>=begin)
		{
			array[end+1] = array[end];
			end--;
		}
		array[begin] = temp;
	}
}
void ShellSort(int* array, int size)//希尔排序
{
	int gap = 3;
	while (gap>0)
	{
		for (int i = gap; i < size; i++)
		{
			int temp = array[i];
			int end = i - gap;
			while (end >= 0 && temp < array[end])
			{
				array[end + gap] = array[end];
				end-=gap;
			}
			array[end + gap] = temp;
		}
		gap--;
	}
}
void SelectSort(int* array, int size)//选择排序
{
	
	for (int j = 0; j < size - 1; j++)
	{
		int max_pos = 0;
		for (int i = 1; i < size - j; i++)
		{
			if (array[i]>array[max_pos])
				max_pos = i;
		}
		if (max_pos != size - j - 1)
			Swap(&array[max_pos], &array[size - 1 -j]);
	}	
}
void Swap(int* num1, int*num2)//交换
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void SelectSort2(int* array, int size)//双向选择排序
{
	int begin = 0;
	int end = size - 1;
	while (begin<end)
	{
		int min = begin;
		int max = begin;
		int index =begin + 1;
		while (index<=end)
		{
			if (array[index]>array[max])
				max = index;
			if (array[index] < array[min])
				min = index;
			index++;
		}
		if (max != end)
		{
			Swap(&array[max], &array[end]);
			if (min == end)
				min = max;
		}
		if (min != begin)
		{
			Swap(&array[min], &array[begin]);
			if (max == begin)
				max = min;
		}
		begin++;
		end--;
	}
}
void HeapSort(int* array, int size)//堆排序
{
	//创建堆
	int root = (size - 2) / 2;
	for(; root >= 0; root--)
	{
		HeapAdJust(array,size,root);
	}
	int end = size - 1;
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdJust(array, end, 0);
		end--;
	}
}
void HeapAdJust(int* array, int size, int parent)//调整
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size &&array[child + 1] > array[child])
		{
			child += 1;
		}
		if ( array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void QuickSort(int* array, int left, int right)//快排
{
	if (right-left <= 1)
		return;
	int div = Partion(array,left,right);
	QuickSort(array, left, div);
	QuickSort(array, div, right);
}
int  Partion(int* array, int left, int right)//分割
{
	int key = array[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin<end)
	{
		while (begin<end && array[begin]<=key)
		{
			begin++;
		}
		while (begin<end&&array[end] >= key)
		{
			end--;
		}
		if (begin < end)
		{
			Swap(&array[begin], &array[end]);
		}
	}
	if (begin != right - 1)
	{
		Swap(&array[begin], &array[right - 1]);
	}
	return begin;
}
void QuickSortNor(int* array, int size)//快排非递归
{
	pStack s;
	StackInit(&s);
	PushBack(&s, size);
	PushBack(&s, 0);
	while (!StackEmpty(s))
	{
		int left = 0;
		int right = 0;
		int div = 0;
		left = TakeOut(&s);
		PopBack(&s);
		right = TakeOut(&s);
		PopBack(&s);

		if (left < right)
		{
			div = Partion(array, left, right);
			PushBack(&s, right);
			PushBack(&s, div + 1);
			PushBack(&s, div);
			PushBack(&s, left);
		}
	}
}
void Merge(int* array, int size)//归并排序
{
	int* temp = (int*)malloc(size*(sizeof(array[0])));
	if (temp == NULL)
	{
		return;
	}

	_MergeSort(array,0,size,temp);
	free(temp);
}
void MergeData(int* array, int left, int mid, int right, int*temp)//归并数据
{
	int beginL = left;
	int endL = mid;
	int beginR = mid;
	int endR = right;
	int index = left;//索引

	while (beginL<endL && beginR<endR)
	{
		if (array[beginL] <= array[beginR])
		{
			temp[index++] = array[beginL++];
		}
		else
		{
			temp[index++] = array[beginR++];
		}
	}

	while (beginL<endL)
	{
		temp[index++] = array[beginL++];
	}

	while (beginR<endR)
	{
		temp[index++] = array[beginR++];
	}
}
void _MergeSort(int* array, int left, int right, int* temp)//递归归并
{
	if (right-left>1)
	{
		int mid = left + (right - left) / 2;
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid, right, temp);
		MergeData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, sizeof(array[0])*(right-left));
	}
}
void MergeNor(int* array, int size)//归并排序非递归
{
	int* temp = (int*)malloc(size*sizeof(array[0]));
	if (temp == NULL)
	{
		return;
	}
	int gap = 1;//归并的两组数有多少个数字(归并间隔)
	while (gap<size)
	{
		for (int i = 0; i < size;i+=gap*2)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid>size)
				mid = size;
			if (right > size)
				right = size;

			MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, size*sizeof(array[0]));
		gap *= 2;
	}
}
void CountSort(int* array, int size)//计数排序
{
	int max = array[0];
	int min = array[0];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i]>max)
		{
			max = array[i];
		}
		if (array[i]<min)
		{
			min = array[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(range*sizeof(int));
	if (count==NULL)
	{
		assert(0);
		return;
	}
	memset(count, 0, range*sizeof(int));
	for (int i = 0; i < size; i++)
	{
		count[array[i]-min]++;
	}
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			array[index++] = i + min;
		}
	}
	free(count);
}
void RadixSort(int* array, int size)//基数排序
{
	int* temp = (int*)malloc(size*sizeof(array[0]));
	if (temp == NULL)
	{
		assert(0);
		return;
	}

	Radix(array,size,temp);
	free(temp);
}
void Radix(int* array, int size, int* temp)//排序
{
	//统计每个桶中元素的个数
	int max = array[0];
	for (int i = 0; i < size; i++)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}
	int bit_count = 1;
	while (max /= 10)
	{
		bit_count++;
	}
	int radix = 1;
	while (bit_count--)
	{
		int count[10] = { 0 };
		int startAddr[10] = { 0 };
		for (int i = 0; i < size; i++)
		{
			count[array[i]/radix % 10]++;
		}

		//计算每个桶的起始地址
		for (int i = 1; i < 10; i++)
		{
			startAddr[i] = startAddr[i - 1] + count[i - 1];
		}

		//放入元素
		for (int i = 0; i < size; i++)
		{
			int budketNo = array[i] / radix % 10;
			temp[startAddr[budketNo]++] = array[i];
		}

		//回收
		memcpy(array, temp, size*sizeof(array[0]));
		radix *= 10;
	}


	
	
}