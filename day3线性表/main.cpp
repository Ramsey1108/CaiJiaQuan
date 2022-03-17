#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<cstdio>
#include<string.h>
#include <string>
#include<stdlib.h>
using namespace std;
#define MaxSize 50
typedef int ElemType;
//静态分配
typedef struct {
	ElemType data[MaxSize];
	int lenth;//当前顺序表的元素个数
}Sqlist;
//插入元素函数
bool ListInser(Sqlist& L, int post, ElemType e)
{
	if (post<1 || post>L.lenth + 1)//判断要插入的位置是否合法
		return false;
	if (L.lenth > MaxSize)//超出空间了
		return false;
	for (int j = L.lenth; j >= post; j--)//从最后的元素开始向后移动元素post是位置
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[post - 1] = e;//腾出的位置给e
	L.lenth++;//长度+1
	return true;
}
//打印顺序表
void PrintList(Sqlist& L)
{
	for (int i = 0; i < L.lenth; i++)
	{
		printf("%3d", L.data[i]);//所有元素打印到一排
	}
	cout << endl;
}
//删除元素函数
bool ListDel(Sqlist& L, int post, ElemType& e)
{
	if (post<1 || post>L.lenth)//删除位置不合法,lenth是用户眼中的位置
		return false;
	if (L.lenth == 0)//表中没有元素，无需删除
		return false;
	e = L.data[post - 1];//把要删的元素先拿出来
	//拿出来以后再把后面的元素一次往前移
	for (int j = post; j < L.lenth; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.lenth--;//表的长度-1
	return true;

}
//删除元素函数
int LocalElem(Sqlist& L, ElemType e)
{
	for (int i = 0; i < L.lenth; i++)//遍历链表
	{
		if (L.data[i] == e)
			return i + 1;//如果找到了就返回位置(从0开始返回给用户视角要+1)；
	}
	return 0;//找不到就会返回这个
}
/*
初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，
然后通过scanf读取一个元素（假如插入的是6），插入到第2个位置，
打印输出顺序表，每个元素占3个空格，格式为1  6  2  3，
然后scanf读取一个整型数，是删除的位置（假如输入为1），
然后输出顺序表  6  2  3，假如输入的位置不合法，输出false字符串
*/
int main()
{
	Sqlist L;//定义一个顺序表
	bool ret;//查看返回值（是否删除成功）
	ElemType del;//用来存要删除的元素
	//现在顺序表是空的，把他装点东西
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.lenth = 3;
	//oj实现
	int temp;//要插入的数字
	cin >> temp;
	ret = ListInser(L, 2, temp);
	PrintList(L);
	int del_post;//要删除的数字
	cin >> del_post;
	ret = ListDel(L, del_post, del);
	if (ret)
	{
		//cout << "插入成功" << endl;
		PrintList(L);
	}
	else
	{
		cout << "false" << endl;
		//PrintList(L);
	}
	 
	//测试删除
	//ret = ListDel(L, 1,del);
	//if (ret)
	//{
	//	cout << "删除成功" << endl;
	//	printf("删除的元素是%d\n", del);
	//	PrintList(L);
	//}
	//else
	//{
	//	cout << "删除失败" << endl;
	//	//PrintList(L);
	//}

	//测试查找元素
	//int elem_post;//定义查找元素在表的位置
	//elem_post = LocalElem(L, 7);//用这个来接收返回的位置
	//if (elem_post)//返回非0都是真
	//{
	//	cout << "查找成功" << endl;
	//	cout << "元素位置为:" <<elem_post<< endl;

	//}
	//else
	//{
	//	cout << "查找失败" << endl;
	//}
	return 0;

}