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
