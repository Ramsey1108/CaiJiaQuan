#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType* elem;//存储元素的起始地址
	int TableLen;//元素个数
}SSTable;
//初始化随机生成数数
void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));//随机数生成，每一次执行代码就会得到随机的10个元素
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;//生成的是0-99之间
	}
}
//打印数组
void ST_print(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//交换两个变量
void swap1(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}
//冒泡排序(从小到大)
void BubbleSort(ElemType A[], int n)
{
	int i, j;
	bool Flag;
	for (i = 0; i < n - 1; i++)//外层控制多少个有序
	{
		Flag = true;
		for (j = n - 1; j > i; j--)//内层控制比较的数字
		{
			if (A[j - 1] > A[j])
			{
				swap1(A[j - 1], A[j]);
				Flag = false;
			}
		}
		if (Flag)
		{
			break;
		}
	}
}
//快排要用的划分
int Partition(int* arr, int left, int right)
{
	int k, i;
	for (i = k = left; i < right; i++)
	{
		if (arr[i] < arr[right])
		{
			swap1(arr[i], arr[k]);
			k++;
		}
	}
	swap1(arr[k], arr[right]);
	return k;
}
//递归实现快排
void QuickSort(ElemType A[], int low, int high)
{
	if (low < high)//分而治之思想
	{
		int positive = Partition(A, low, high);
		QuickSort(A, low, positive - 1);
		QuickSort(A, positive + 1, high);
	}
}
int main()
{
	SSTable T;
	ST_Init(T, 10);
	ST_print(T);
	//BubbleSort(T.elem, T.TableLen);
	QuickSort(T.elem, 0, T.TableLen-1);//传的是数组下标的值
	ST_print(T);
}