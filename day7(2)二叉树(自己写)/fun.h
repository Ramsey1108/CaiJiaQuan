#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//作者 王道训练营 龙哥
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType data;//c就是书籍上的data
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

typedef struct tag {
	BiTree p;//树的某一个结点的地址值
	struct tag* pnext;
}tag_t, * ptag_t;

//栈的相关数据结构
#define MaxSize 50
typedef BiTree ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;
//队列相关结构
//队列的相关数据结构
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
//栈的函数声明
void InitStack(SqStack& S);
bool Push(SqStack& S, ElemType x);
bool Pop(SqStack& S, ElemType& x);
bool StackEmpty(SqStack& S);
//队列的函数声明
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
bool DenQueue(LinkQueue& Q, ElemType& e);
void EnQueue(LinkQueue& Q, ElemType x);