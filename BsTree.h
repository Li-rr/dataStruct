//二叉排序树的存储结构
typedef int KeyType; 
typedef struct BSTNode{
	KeyType key;
	struct BSTNode *lchild, *rchild;
} BSTNode;
typedef BSTNode *BSTree;

/*
 *递归查找二叉排序树T中是否存在key
 */
int BST_search(BSTree T,KeyType key, BSTree &p)
{
	if(!T)
	{
		return 0;
	}
	else
	{
		if(key == T -> key )
		{
			p = T;
			return 1;
		}
		else if(key > T -> key)
		{
			 BST_search(T->rchild,key,p);
		}
		else
		     BST_search(T->lchild,key,p);
	}
}
/*
 *非递归查找算法
 */
int B(BSTree T,KeyType key)
{
	BSTree	 P = T;
	while(P)
	{	
		if(key == T -> key)
		  return 1;
		else if(key<T -> key)
		  T=T->lchild;
		else
		  T=T->rchild;
	}
	return 0;
}

/*
 *插入节点的递归算法
 */
int BST_insert(BSTree &T, KeyType data)
{
	if(!T)
	{
		T = new BSTNode;
		T -> key = data;
		T -> rchild = NULL;
		T -> lchild = NULL;
		return 1;
	}
	if(data == T -> key)
	{
		return 0;
	}
	if(data > T -> key )
	{
		 BST_insert(T->rchild,data);
	}
	else
	{
		 BST_insert(T->lchild,data);
	}
}

void BST_order(BSTree T)
{
	if(!T)
	  return;
	BST_order(T->lchild);
	cout<<T->key<<" ";
	BST_order(T->rchild);
}
int Delete(BSTree T)
{
	//从二叉排序数中删除节点T,并重新链接它的左右子树
	BSTree q,s;
	if( !T -> lchild && !T -> rchild)
		T=NULL;
	else if(!T->lchild) //左子树为空
	{
		q = T;
		T = T -> rchild;
		delete q;
	}else if(!T -> rchild)
	{
		q = T;
		T = T -> lchild;
		delete q;
	}
	else      //左右子数均不为空
	{
		q = T;
		s = T -> lchild;

		while(s->rchild)
		{
			q = s;
			s = s->rchild; 
		}

		T -> key = s -> key;
		if(T != q)
		  q -> rchild = s->lchild;
		else
		  q->lchild = s->lchild;
		delete s;
	}
	return 1;
}
int BST_delete(BSTree T,int key)
{
	if(!T)
	{
		return 0;
	}
	else
	{
		if(key == T->key)
			Delete(T);
		else if( key < T->key)
		  BST_delete(T->lchild,key);
		else
		  BST_delete(T->rchild,key);
	}

}

void BST_create(BSTree &T)
{
	T=NULL;
	KeyType data;
	cout<<"<--enter data,end with 0-->\n";
	cin>>data;
	while(data)
	{
	BST_insert(T,data);
	cin>>data;
	}
}




