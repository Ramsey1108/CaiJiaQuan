#include "fun.h"
void InitStack(SqStack& S)
{
	S.top = -1;
}
//入栈
bool Push(SqStack& S, ElemType x)
{
	if (S.top == MaxSize - 1)
	{
		return false;
	}
	S.data[++S.top] = x;
	return true;
}
//出栈
bool Pop(SqStack& S, ElemType& x)
{
	if (-1 == S.top)
		return false;
	x = S.data[S.top--];
	return true;
}
//判断是否为空
bool StackEmpty(SqStack& S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}