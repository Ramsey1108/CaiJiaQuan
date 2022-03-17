#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
	ElemType data;//
	struct LNode* next;//指向下一节点
}LNode, * LinkList;
//头插法建立新链表
LinkList CreatList1(LinkList& L)//二级指针
{
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));//申请空间给带头结点的链表
	L->next = NULL;//头结点没东西
	cin >> x;
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//申请一个空间给输入进来的s
		s->data = x;//读到的值放进x
		s->next = L->next;//先从后面修改指针
		L->next = s;//头结点指向新进来的x
		cin >> x;
	}
	return L;
}
//尾插法建立新链表
LinkList CreatList2(LinkList& L)//二级指针
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));//申请空间给带头结点的链表
	LNode* s, * r = L;//r代表表尾指针，不用L是因为怕弄乱用变量r代替
	cin >> x;
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//申请一个空间给输入进来的s
		s->data = x;//读到的值放进x
		r->next = s;
		r = s;//r指向新进来的地方
		cin >> x;
	}
	r->next = NULL;//最后把表位指针赋值null不然输出判断null的时候不行造成非法访问
	return L;
}
void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
		/*if (L != NULL)
		{
			printf(" ");
		}*/
	}
	printf("\n");
}
//通过位置查找元素的值
LinkList LlemGet(LinkList L, int i)//i是要查找的位置
{
	int j = 1;
	LinkList p = L->next;//一开始就指向第一个元素而不是头指针
	if (0 == i)
	{
		return L;//找0就是找头指针
	}
	if (i < 1)
	{
		return NULL;//找小于1的就是无
	}
	while (p && j < i)//正常的位置比如3
	{
		p = p->next;//找个指针往下移动，游标跟着动
		j++;
	}
	return p;
}
//通过元素查找位置
LinkList LocalElem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}
//往第i个位置插入元素
bool ListFrontInser(LinkList L, int i, ElemType e)//要插入的链表，位置，具体值
{
	LinkList p = LlemGet(L, i - 1);//找到i-1个位置
	if (NULL == p)
	{
		return false;//i越界了
	}
	LinkList s = (LinkList)malloc(sizeof(LNode));//给新节点申请空间
	s->data = e;//把要插入的值放进去
	s->next = p->next;//先让新节点指向后面的
	p->next = s;//再让新节点前面的指向插入的
	return true;
}
//删除第i个位置上的元素
bool ListDelete(LinkList L, int i)
{
	LinkList p = LlemGet(L, i - 1);//拿到第i-1的节点
	if (NULL == p) 
	{
		return false;
	}
	LinkList q = p->next;//定义一个q去指向要删除的节点
	p->next = q->next;//让删除元素的前驱指向删除元素的后继
	free(q);	
	q = NULL;
	return true;
}
int main()
{
	LinkList L;
	LinkList search;//保存找到位置的节点
	/*CreatList1(L);
	PrintList(L);*/
	CreatList2(L);
	//PrintList(L);
	/*search = LlemGet(L, 3);
	if (search != NULL)
	{
		cout << "按序号查找成功" << endl;
		cout << "元素是:" << search->data;
	}*/
	LinkList temp=LlemGet(L, 2);
	cout << temp->data<<endl;
	ListFrontInser(L, 2, 99);//再第二个位置插入878
	PrintList(L);
	ListDelete(L, 4);//删除链表第四个元素
	PrintList(L);

}