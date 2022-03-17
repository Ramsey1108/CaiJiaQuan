#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//数组
	int top;
}SqStack;
void InitStack(SqStack& S)
{
	S.top = -1;//代表栈为空
}

//入栈
bool Push(SqStack& S, ElemType x)
{
	if (S.top == MaxSize - 1)//数组的大小不能改变，避免访问越界
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
	x = S.data[S.top--];//后减减，x=S.data[S.top];S.top=S.top-1;
	return true;
}


typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];//数组,存储MaxSize-1个元素
	int front, rear;//队列头 队列尾
}SqQueue;

void InitQueue(SqQueue& Q)
{
	Q.rear = Q.front = 0;
}

//入队
bool EnQueue(SqQueue& Q, ElemType x)
{
	if ((Q.rear + 1) % MaxSize == Q.front) //判断是否队满
		return false;
	Q.data[Q.rear] = x;//3 4 5 6
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}
//出队
bool DeQueue(SqQueue& Q, ElemType& x)
{
	if (Q.rear == Q.front)
		return false;
	x = Q.data[Q.front];//先进先出
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
int main()
{
	SqStack S;//先进后出 FILO  LIFO
	bool flag;
	ElemType m;//用来存放拿出的元素
	InitStack(S);//初始化
	int i, num;
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &num);
		Push(S, num);
	}
	for (i = 0; i < 3; i++)
	{
		Pop(S, m);
		printf("%2d", m);
	}
	printf("\n");
	SqQueue Q;
	InitQueue(Q);
	for (i = 0; i < 5; i++)//入队5个元素，最后一个元素不会入队成功
	{
		scanf("%d", &num);
		flag = EnQueue(Q, num);
		if (false == flag)
		{
			printf("false\n");
		}
	}
	ElemType element;
	for (i = 0; i < 4; i++)//出队4个元素并打印每一个
	{
		DeQueue(Q, element);
		printf("%2d", element);
	}
	printf("\n");
}