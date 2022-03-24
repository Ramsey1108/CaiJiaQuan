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
void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len + 1;//实际申请11个元素的空间
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;//随机了11个数，但是第一个元素是没有用到的
	}
}
void ST_print(SSTable ST)
{
	for (int i = 1; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//插入排序，从小到大排序，升序
void InsertSort(ElemType A[], int n)
{
	int i, j;
	//24 66 94  2 15 74 28 51 22 18  2
	for (i = 2; i <= n; i++)//第零个元素是哨兵，从第二个元素开始拿，往前面插入
	{
		if (A[i] < A[i - 1])//①如果后面一个比前面一个元素小
		{
			A[0] = A[i];//②就把后面的元素放到哨兵那里去
			for (j = i - 1; A[0] < A[j]; --j)//③这里是跟左边已经有序的比，当满足要插入的元素比有序中某一个元素要小的时候
				A[j + 1] = A[j];//④把有序数列中每一个元素跟要插入要素的比，比他大就往后覆盖
			A[j + 1] = A[0];//⑤当退出循环的时候j刚好指向没有比要插入元素数列中再大的元素了，所以有个重复
			//的元素插入了比如 [2] 1 3 3 4 5 6 7 这时候就把2插入到第一个3出现的位置
		}
	}
}
//交换函数
void swap(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}
//选择排序
void SelectSort(ElemType A[], int n)
{
	int i, j, min;//记录最小的数的下标
	for ( i = 0; i < n-1; i++)
	{
		min = i;
		for ( j = i+1; j < n; j++)
		{
			if (A[j]<A[min])
			{
				min = j;
			}
		}
		if (min!=i)
		{
			swap(A[i], A[min]);
		}
	}
}
int main()
{
	SSTable T;
	ST_Init(T, 10);
	//ST_print(T);
	//BubbleSort(T.elem, T.TableLen);
	int a[] = { 12 ,63, 58, 95, 41 ,35, 65,  0 ,38, 44 };
	//T.elem = a;
	//InsertSort(a, 10);//传的是数组下标的值
	//ST_print(T);
	SelectSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
}