
/*************************************************************************
	> File Name: two-tree.cpp
	> Author: ma6174
	> Mail: ma6174@163.com
	> Created Time: 2016年11月03日 星期四 20时08分06秒
 ************************************************************************/
#include<iostream>
using namespace std;
typedef char elementType;
typedef struct lBNode{
	elementType data;
	struct lBNode * lChild, * rChild; //left,right child
} BiNode,* Bitree;
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
//
void createBiTree2(Bitree &T)
{
	char c;
	cin >> c;
	if('#' == c)
		T = NULL;
	else
	{
		T = new BiNode;
		T->data = c;
		createBiTree(T->lChild);
		createBiTree(T->rChild);
	}

}
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
//
//
//
void InOrder(Bitree T)
{
	if(T)
	{
		InOrder( T -> lChild);
		Visit(T);
		InOrder( T -> rChild);
	}
}
//
//
//
void PostOrder(Bitree T)
{
	if(T)
	{
		PostOrder( T -> lChild );
		PostOrder( T -> rChild );
		Visit(T);
	}
}
// get subTree length
int BiTreeDepth(Bitree T)
{
	int m,n;
	if(!T)
		return 0;
	else
	{
		m = BiTreeDepth(T -> lChild );
		n = BiTreeDepth(T -> rChild );
		return (m > n ? m : n ) + 1;
	}
}
//
//
//get subTree leaf number
void BiTreeLeaf(Bitree T,int &num)
{

	if(!T)
		return;

		BiTreeLeaf(T->lChild,num);

		BiTreeLeaf(T->rChild,num);
		if(!T->lChild&&!T->rChild)
		{
				num++;
		}
}

void print()
{
	cout<<"|---------------------------------------------------|\n";
	cout<<"|========= enter 1 to create BiTree ================|\n";
	cout<<"|========= enter 2 to preorder this tree ===========|\n";
	cout<<"|========= enter 3 to Inoreder this tree ===========|\n";
	cout<<"|========= enter 4 to Postorder this tree ==========|\n";
	cout<<"|========= enter 5 get this tree depth =============|\n";
	cout<<"|========= enter 6 get this tree leaf number =======|\n";
	cout<<"|========= enter 0 to end ==========================|\n";
	cout<<"|---------------------------------------------------|\n";
}
int main()
{
	Bitree T;
	int num=0,control,high=0;
	print();
	cin >> control;
	while(control)
	{
		switch(control)
		{
		case 1: createBiTree(T); break;

		case 2: PreOrder(T); break;
		case 3: InOrder(T); break;
		case 4: PostOrder(T);break;
		case 5: cout<<BiTreeDepth(T)<<endl; break;
		case 6: BiTreeLeaf(T,num);cout<< num <<endl; break;
		default : cout<<"enter worror!\n"; break;
		}
		cout<<"\n rechoice: ";
		cin>>control;
	}

	return 0;
}
