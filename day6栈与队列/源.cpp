#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MaxSize 5
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;
//初始化栈
void InitStack(SqStack& S) //要改变栈的内容所以要加取地址
{
	S.top = -1;
}
//判断栈是否为空
bool StackEmpty(SqStack S)
{
	if (S.top == -1)
	{
		return true;
	}
	return false;
}
//入栈
bool push(SqStack& S, ElemType e)
{
	if (S.top == MaxSize - 1)//栈满
	{
		return false;
	}
	S.data[++S.top] = e;
	return true;
}
//获取栈顶元素
bool GetTop(SqStack S, ElemType& m)//取地址m是因为拿到的m要传递出去
{
	if (StackEmpty(S))//栈是空的就没栈顶元素了
	{
		return false;
	}
	m = S.data[S.top];
	return true;
}
//弹出栈顶元素
bool Pop(SqStack& S, ElemType& m)
{
	if (StackEmpty(S))//栈是空的就没栈顶元素了
	{
		return false;
	}
	m = S.data[S.top];
	S.top--;
	return true;
}