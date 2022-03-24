#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#define N 10
using namespace std;
typedef int ElemType;
//一直要递归用的合并数组的
void Merge(ElemType A[], int low, int high, int mid)
{
	//int* B = new int[high - low + 1];
	int* B = (ElemType*)malloc(sizeof(ElemType) * (10));
	//ElemType B[N];
	int i, j, k;
	for (k = low; k <= high; k++)//复制元素到B中
		B[k] = A[k];
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)//合并两个有序数组
	{
		if (B[i] <= B[j])
			A[k] = B[i++];
		else
			A[k] = B[j++];
	}
	while (i <= mid)//如果有剩余元素，接着放入即可
		A[k++] = B[i++];
	while (j <= high)
		A[k++] = B[j++];
}
//归并排序
void MergeSort(ElemType A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, high, mid);
	}
}

int main()
{
	int A[] = { 12 ,63, 58, 95, 41, 35, 65 , 0, 38, 44 };
	MergeSort(A, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", A[i]);
	}
}