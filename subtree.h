/*************************************************************************
	> File Name: subtree.h
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年11月09日 星期三 19时49分20秒
 ************************************************************************/

#include <iostream>
using namespace std;
typedef char elementType;
typedef struct lBNode
{
	elementType data;
	struct lBNode * lChild, * rChild;
}BiNode,*BiTree;

//create Subtree
void  createSubTree(Bitree q,int k)
{
	//q->root node
	//k=1 --left subtree,k=2 --right subtree
	elementType x;
	Bitree u;
	cin>>x;
	if(x!='#')
	{
		u = new BiNode;
		u -> data = x;
		u -> lChild = NULL;
		u -> rChild = NULL;
		if(k==1)
			q->lChild = u;
		if(k==2)
			q->rChild = u;
		createSubTree(u,1);
		createSubTree(u,2);
	}
}
//create binary tree
void createBiTree(Bitree &BT)
{
	Bitree p;
	char x;
	cout<<"please according to preorder traversal enter binary tree ,end with '#':"<<endl;
	cin>>x;
	if(x=='#')
		return;
	BT = new BiNode;
	BT->data=x;
	BT->lChild=NULL;
	BT->rChild=NULL;
	p=BT;
	createSubTree(p,1); //create root node left subtree
	createSubTree(p,2); //create root node right subtree
}
//
//
void Visit(Bitree T)
{
	if(T -> data != '#')
		cout<<T->data;
}
//
//
//
void PreOrder(Bitree T)
{
	if(T)
	{
		Visit(T); 
		PreOrder(T->lChild);
		PreOrder(T->rChild);
	}
}



