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
	typedef struct {
		ElemType data[MaxSize];//数组存储MaxSize-1个元素
		int front, rear;//队列头，队列尾
	}SqQueue;
	//初始化队列
	void InitQueue(SqQueue& Q)
	{
		Q.front = 0;
		Q.rear = 0;
	}
	//判断队列是否为空
	bool IsEmpty(SqQueue Q)//只是判断不需改变
	{
		if (Q.front == Q.rear)
		{
			return true;
		}
		return false;
	}
	//入队
	bool EnQueue(SqQueue& Q, ElemType e)
	{
		if ((Q.rear + 1) % MaxSize == Q.front)//判断是否队满了
		{
			return false;
		}
		Q.data[Q.rear] = e;//放队尾
		Q.rear = (Q.rear + 1) % MaxSize;//本来就要+1
		//但是取余只要不超过maxsize他就还在本来的值，而且还能判断+1后是否跟对头指针重合
		return true;
	}
	//出队
	bool DenQueue(SqQueue& Q, ElemType& e)
	{
		if (IsEmpty(Q))
		{
			return false;
		}
		e = Q.data[Q.front];
		Q.front = (Q.front + 1) % MaxSize;
		return true;
	}
	int main()
	{
		//队列的
		SqQueue Q;
		bool ret;
		ElemType e;//存储出队元素
		InitQueue(Q);
		//栈的
		SqStack S;
		ElemType m;//拿来存取获取到的栈顶元素;
		bool Flag;
		InitStack(S);
		//变量实现
		ElemType temp3;
		//开始实现栈的
		for (int i = 0; i < 3; i++)
		{
			cin >> temp3;
			push(S, temp3);
		}
		ElemType x;//拿来存取获弹出来的栈顶元素;
		for (int i = 0; i < 3; i++)
		{
			Pop(S, x);
			printf("%2d", x);
		}
		cout << endl;
		//开始实现队列的
		ElemType temp2;
		for (int i = 0; i < MaxSize; i++)
		{
			
			cin >> temp2;
			ret=EnQueue(Q, temp2);
			if (!ret)
			{
				cout << "false" << endl;
			}
		}
		//出队
		ElemType temp1;
		for (int i = 0; i < MaxSize-1; i++)
		{
			DenQueue(Q, temp1);
			printf("%2d", temp1);
		}
		cout << endl;
		return 0;
	}