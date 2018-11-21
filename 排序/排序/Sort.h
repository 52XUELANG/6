#define _CRT_SECURE_NO_WARNINGS

/*排序：
排序稳定性：对于一组数据中相同的元素，排完序之后的顺序与未排序之前的顺序相同，在前面的还是在前面

插入排序：每一步将一个待排序的元素，按其排序码的大小，插入前面有序数列中的合适位置
          最优情况：时间效率为O(n)；
		  最差情况：时间效率为O(n²)；
		  空间复杂度：O(1);
		  适合情况：数据量小，数据接近有序
		  稳定性:稳定的排序方法

希尔排序：将一组数据按照一个间隔大小进行分组(例：array[] ={9,8,7,6,5,4,3,2,1},gap=3,第一组:9,6,3;第二组:8,5,2;第三组:7,4,1),
          每次将一组的数据进行插入排序，然后gap-1，再进行一次.
		  时间复杂度:n^1.25到1.6*n^1.25之间
		  适合情况:数据量较大,数据杂乱
		  稳定性:不稳定的排序方法(每一组数据中间会隔开部分数据,导致不稳定)

选择排序：遍历数据，选择最大的数按升序或者降序放到数列尾或者数列头，然后继续遍历其他的数据
          时间复杂度:O(n²)
		  稳定性:不稳定的排序方式
		  缺陷:重复性的比较工作(堆排序可以优化)
		  场景:元素少，重复性的元素多，减少比较次数
堆排序:   利用堆的性质和结构来进行排序
          空间复杂度:O(1)
	      时间复杂度:O(N*logN)
	      稳定性:不稳定
冒泡排序:遍历数据，如果相邻的两个数据前一个大于(或者小于,取决于排序方式)后一个,则进行交换,一次遍历之后，遍历个数少一
         空间复杂度:O(1)
		 时间复杂度:O(N²)
		 稳定性:稳定,没有跨区间交换
快速排序:在数据中找取一个基准值，将数据分割为左右两部分，一边大于基准值，一边小于基准值，然后再对两边进行再次快排
         空间复杂度:O(1)
		 时间复杂度:O(N²)[最差情况:升序转降序、降序转升序]
		 稳定性:不稳定
归并排序:将数据进行分块，让每一块都有序，然后进行融合(类似于将两个有序链表合并成一个有序链表),递归划分空间
         时间复杂度:O(N*logN)
		 空间复杂度:
		 稳定性:稳定排序
		 适用:数据量大
计数排序:将所给数据遍历，然后给对应的大小的Count的数值+1，再将统计的数据按照大小存入初始数组
         时间复杂度:O(N)
		 空间复杂度:O(M)
		 场景:数据在一定范围内较为密集
基数排序:将一组数据的每一个数的每一位进行比较排序
         时间复杂度:O(N)
*/

#ifndef __SORT_H__
#define __SORT_H__
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
void InsertSort(int* array,int size);//插入排序
void InsertSortBetter(int* array, int size);//用二分查找优化插入排序
void ShellSort(int* array, int size);//希尔排序
void SelectSort(int* array, int size);//选择排序
void Swap(int* num1, int*num2);//交换
void SelectSort2(int* array, int size);//双向选择排序
void HeapSort(int* array, int size);//堆排序
void HeapAdJust(int* array, int size, int root);//调整
void QuickSort(int* array, int left,  int right);//快排
int Partion(int* array, int left, int right);//分割
void QuickSortNor(int* array, int size);//快排非递归
void Merge(int* array,int size);//归并排序
void MergeData(int* array,int left, int mid, int right, int*temp);//归并数据
void _MergeSort(int* array,int left,int right,int* temp);//递归归并
void MergeNor(int* array, int size);//归并排序非递归
void CountSort(int* array, int size);//计数排序
void RadixSort(int* array, int size);//基数排序
void Radix(int* array,int size, int* temp);//排序




#endif