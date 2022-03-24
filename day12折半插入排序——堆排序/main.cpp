#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType* elem;//整型指针
	int TableLen;
}SSTable;
void ST_print(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
// 挖坑法，王道书上使用的方法，最左边作为分割值
int Partition1(ElemType A[], int low, int high)
{
	ElemType pivot = A[low];//把最左边的值暂存起来
	while (low < high)
	{
		while (low < high && A[high] >= pivot)

		{
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
		{
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
//递归实现快排
void QuickSort(ElemType A[], int low, int high)
{
	if (low < high)//分而治之思想
	{
		int positive = Partition1(A, low, high);
		QuickSort(A, low, positive - 1);
		QuickSort(A, positive + 1, high);
	}
}
//折半查找 插入排序，考的很少
void MidInsertSort(ElemType A[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		A[0] = A[i];
		low = 1; high = i - 1;//low有序序列的开始，high有序序列的最后
		while (low <= high)//先通过二分查找找到待插入位置
		{
			mid = (low + high) / 2;
			if (A[mid] > A[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; --j)
			A[j + 1] = A[j];
		A[high + 1] = A[0];
	}
}
//自己的
void MidInsertSort1(ElemType A[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		A[0] = A[i];//哨兵元素
		low = 1; high = i - 1;//因为0是哨兵元素所以low从1开始，high的n-1是数组原因
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (A[mid] > A[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; --j)
			A[j + 1] = A[j];
		A[j + 1] = A[0];

	}
}
int main()
{
	SSTable ST;
	ElemType A[] = { 0,64, 94, 95, 79, 69, 84, 18, 22, 12 ,78 };
	//QuickSort(A, 0, 9);
	MidInsertSort1(A, 10);
	for (int i = 0; i < 11; i++)
	{
		printf("%3d", A[i]);
	}
	printf("\n");
}