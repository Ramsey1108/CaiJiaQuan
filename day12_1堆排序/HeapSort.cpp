#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType* elem;
	int TableLen;
}SSTable;
//弄随机数组测试一下看看是不是每次都能有序，避免巧合性
void ST_Init(SSTable &ST,int len)//申请空间，并进行随机数生成
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
}
//打印
void ST_print(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//交换元素
 void swap(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}
//调整子树
void AdjustDown1(ElemType A[], int k, int len)
{
	int dad = k;
	int son = 2 * dad + 1; //左孩子下标(公式)
	while (son <= len)
	{
		if (son + 1 <= len && A[son] < A[son + 1])//看下有没有右孩子，比较左右孩子选大的
		{
			son++;//如果右孩子比左孩子大，那就选大的，son++就是选了右孩子了
		}
		if (A[son] > A[dad])//比较孩子和父亲，如果孩子比父亲大，交换，然后再把交换后再调整为大根堆
		{
			swap(A[son], A[dad]);
			dad = son;
			son = 2 * dad + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort1(ElemType A[], int len)
{
	int i;
	//建立大顶堆
	for (i = len / 2; i >= 0; i--)//最后一个父亲的下标=len / 2 （公式规律来的）
	{
		AdjustDown1(A, i, len);
	}
	swap(A[0], A[len]);//交换顶部和数组最后一个元素

	for (i = len - 1; i > 0; i--)//这里传参有点不太懂！！
	{
		AdjustDown1(A, 0, i);//剩下元素调整为大根堆，这里传0是因为（通过顶端的数下降）
		swap(A[0], A[i]);
	}
}
//选择排序（自己写）自己写失败....
void SelectSort(ElemType A[], int len)
{
	int i, j, min;//min来存最小数字的下标
	for ( i = 0; i < len-1; i++)//这里i取len-1是因为内层j = i+1就可以比较到最后一个元素和倒数第二元素了
	{
		min = i;//暂存一下开头的元素
		for ( j = i+1; j < len; j++)//i左边是有序的，现在是找i右边最小的
		{
			if (A[j] < A[min])
				min = j;//把小的下标传过去
		}
		if (min != i)//主要最小的不是本来的有序的最右边那个的，那就把最小的换过来
			swap(A[i], A[min]);
	}
}
int main()
{
	ElemType A[10] = { 12 ,63, 58 ,95 ,41, 35 ,65 , 0, 38 ,44 };
	SSTable ST;
	HeapSort1(A, 9);
	//SelectSort(A, 10);
	//ST_Init(ST, 10);//初始化
	//memcpy(A, ST.elem, sizeof(50));
	//ST_print(ST);
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", A[i]);
	}
	cout << endl;
	SelectSort(A, 10);
	//ST_print(ST);
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", A[i]);
	}
	//cout << endl;
}