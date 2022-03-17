#include "fun.h"
//递归实现
//abdhiejcfg
//前序遍历（深度优先遍历）
void preOrder(BiTree p)
{
	if (p != NULL)
	{
		putchar(p->data);//等价于visit函数
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
//中序遍历
void InOrder(BiTree p)
{
	if (p != NULL)
	{
		InOrder(p->lchild);
		putchar(p->data);//等价于visit函数
		InOrder(p->rchild);
	}
}
//后序遍历
void PostOrder(BiTree p)
{
	if (p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->data);//等价于visit函数
	}
}
//中序遍历非递归
void InOrder2(BiTree T)
{
	SqStack S;
	InitStack(S);//初始化栈
	BiTree p = T;//中间变量接收
	while (p|| !StackEmpty(S))
	{
		if (p)//当一个节点不为空就压栈然后取他的左孩子
		{
			Push(S, p);
			p = p->lchild;
		}
		else//为空就弹出当前元素并且打印然后再取他的右孩子
		{
			Pop(S, p);
			putchar(p->data);
			p = p->rchild;
		}
	}
}
//层次遍历（广度优先遍历）
void LeverOrder2(BiTree T)
{
	LinkQueue Q;//构造辅助队列
	InitQueue(Q);//初始化队列
	BiTree p;//中间变量
	EnQueue(Q, T);//树根入队
	while (!IsEmpty(Q))
	{
		DenQueue(Q, p);//出队当前节点,这里出队还会把出队的地址给p所以可以找到他的左右孩子
		putchar(p->data);
		if (p->lchild != NULL)//入队左孩子
		{
			EnQueue(Q, p->lchild);
		}
		if (p->rchild != NULL)//入队右孩子
		{
			EnQueue(Q, p->rchild);
		}
	}



}
int main()
{
	BiTree tree = NULL;//树根
	BiTree pnew;//每次新建要给的位置
	//二叉树要插入要依靠辅助队列，下面是辅助队列初始化
	ptag_t phead = NULL, ptail = NULL;//队列头指针和队列尾指针
	ptag_t listpnew;
	ptag_t pcur=NULL;//listpnew用来二叉树接收数据以后放进队列的指针,因为选择不对头指针
	//进行遍历，选择用pcur向后遍历
	char c;//用来接收要存储的数据
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')//排除特殊情况
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//给新节点申请空间
		pnew->data = c;//把数放进去
		//树的搞完的要给队列申请空间，两者同步进行
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;//这个队列特殊在他的元素就是pnew的地址，所以树搞定了要给队列listpnew去存树的地址
		if (NULL == tree)//一开始树根都没有的时候
		{
			tree = pnew;//把第一次接进来的数当做树根来放
			phead = listpnew;
			ptail = listpnew;//因为一开始队列啥也没，第一个进来的话既是队头也是队尾
			pcur = listpnew;//当然用来往后走的指针也只能指向这个第一个来的
			continue;
		}
		//因为二叉树的建立要通过辅助队列去实现，所以先操作队列，再进行二叉树的构建
		else//如果不是上面没有树根的情况的话，那就根据队尾指针去判断,同时pcur也跟着移动
		{
			ptail->pnext = listpnew;//先让队列前一个元素的后继指针指向新来的元素
			ptail = listpnew;//再让尾指针始终指向新来的元素因为是尾插法所以新来的一定是队列的最后一个
		}
		//队列搞完了现在对二叉树进行操作
		if (NULL == pcur->p->lchild)//插入始终是看前一个元素的情况，先看左孩子再看又孩子
		{
			pcur->p->lchild = pnew;//左孩子null没有的话那就新来的直接放过去就行了
		}
		else if (NULL == pcur->p->rchild)//如果是右孩子为空的话就放到又孩子里面
		{
			pcur->p->rchild = pnew;
			//重要
			pcur = pcur->pnext;//如果能走到这里，那么说明这个元素的左右孩子都有了，那就要把指针往前后移一位，否则会错误
		}
	}
	printf("--------前序遍历----------\n");
	preOrder(tree);
	cout << endl;
	printf("--------中序遍历----------\n");
	InOrder(tree);
	cout << endl;
	printf("--------后序遍历----------\n");
	PostOrder(tree);
	cout << endl;
	printf("--------中序遍历非递归----------\n");
	InOrder2(tree);
	cout << endl;
	printf("--------层次遍历----------\n");
	LeverOrder2(tree);
	cout << endl;
}
