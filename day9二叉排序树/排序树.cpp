#include "fun.h"
//中序遍历
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%3d", T->key);
		InOrder(T->rchild);
	}
}
//递归插入
int BST_Insert(BiTree& T, KeyType k)
{
	if (NULL == T)
	{	//为新节点申请空间，第一个结点作为树根
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;//代表插入成功
	}
	else if (k == T->key)
		return 0;//发现相同元素，就不插入
	else if (k < T->key)//如果要插入的结点，小于当前结点
		return BST_Insert(T->lchild, k);//函数调用结束后，左孩子和原来的父亲会关联起来
	else
		return BST_Insert(T->rchild, k);
}
//创建二叉排序树
void Creat_BST(BiTree& T, KeyType str[], int n)
{
	T = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(T, str[i]);//把某一个结点放入二叉查找树
		i++;
	}
}
//这个书上没有二叉排序树删除代码--考大题没那么高
void DeleteNode(BiTree& root, KeyType x) {
	if (root == NULL) {
		return;
	}
	if (root->key > x) {
		DeleteNode(root->lchild, x);
	}
	else if (root->key < x) {
		DeleteNode(root->rchild, x);
	}
	else { //查找到了删除节点
		if (root->lchild == NULL) { //左子树为空，右子树直接顶上去
			BiTree tempNode = root;//用临时的存着的目的是一会要free
			root = root->rchild;
			free(tempNode);
		}
		else if (root->rchild == NULL) { //右子树为空，左子树直接顶上去
			BiTree tempNode = root;//临时指针
			root = root->lchild;
			free(tempNode);
		}
		else {  //左右子树都不为空
		   //一般的删除策略是左子树的最大数据 或 右子树的最小数据 代替要删除的节点(这里采用查找左子树最大数据来代替)
			BiTree tempNode = root->lchild;
			if (tempNode->rchild != NULL) {
				tempNode = tempNode->rchild;
			}
			root->key = tempNode->key;
			DeleteNode(root->lchild, tempNode->key);
		}
	}
}
//快排要用的
int compare(const void* left, const void* right)//left，right是任意两个元素的地址值
{
	return *(KeyType*)left - *(KeyType*)right;
	//return *(ElemType*)right - *(ElemType*)left;//从大到小
}
//递归把二叉树的值赋值诶数组
void InOrder1(BiTree T, KeyType str[], int& post)
{
	if (T != NULL)
	{
		InOrder1(T->lchild, str, post);
		//printf("%3d", T->key);
		str[post] = T->key;
		post++;
		InOrder1(T->rchild, str, post);
	}
}
//二分查找
int Binary_Search(KeyType str[], KeyType key, int n)//传数组和要找的数字,还有数组长度
{
	int low = 0, high = n - 1,mid;
	while (low<=high)
	{
		mid = (high + low) / 2;
		if (str[mid] == key)
			return mid;//找到了
		else if (str[mid] >key)
		{
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
}
int main()
{
	BiTree T = NULL;//树根
	BiTree parent;//存储父亲结点的地址值
	BiTree search;
	KeyType str[] = { 87, 7, 60, 80, 59 ,34 ,86, 99 ,21 , 3 };
	KeyType str1[10] = { 0 };
	Creat_BST(T, str, 10);
	//InOrder(T);
	//cout << endl;
	qsort(str1, 10, sizeof(KeyType), compare);//qsort实现的是快排
	//测试
	int post = 0;
	InOrder1(T, str1,post);
	for (int i = 0; i < 10; i++)
	{
		//cout << str1[i] << " ";
		printf("%3d", str1[i]);
	}
	cout << endl;
	int target;
	//cout<< "请输入你想查找的数字:";
	//cin >> target;
	//cout<<"你要找的数字的位置在:"<<Binary_Search(str1, target, 10)<<endl;
	cout << Binary_Search(str1, 21, 10);
}