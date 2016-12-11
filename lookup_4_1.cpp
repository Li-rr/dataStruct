#include <iostream>
using namespace std;
typedef int ElemType;
#include "slnode.h"
#include "sequence_table.h"
#include "BsTree.h"
/*
 *简单顺序查找
 *若找到返回该元素的下标
 *若找不到返回-1
 */
int seq_search(seqList L,ElemType key)
{
    int i = L.listLen-1;
    while( L.data[i] != key )
       { i--;
		if(i==-1)
		  break;
	   }
    return i;

}
/*
 * 利用二分法在一个有序表中
 * 插入一个元素x，
 * 并保持表的有序性
 */
void bin_search(seqList &L,ElemType x)
{
	int mid,low=0,high=L.listLen-1,loc=-1;
	while(low <= high)
	{
		mid = (low + high)/2;
		if( x > L.data[mid-1] && x <= L.data[mid])
		{
			loc = mid;
			break;
		} else if(x < L.data[mid-1])
		{
			high = mid-1;

		}else
		  low = mid+1;
	}
	if(loc!=-1)
	{
		for(int i=L.listLen-1; i >= mid ;i--)
		  L.data[i+1]=L.data[i];
		L.data[mid]=x;
		L.listLen++;
		cout<<"\n<--insert success-->\n";
	}else
	  cout<<"\n error \n";
}
int main()
{
//	seqList Q;
//	int x;
//	initialSeqList(Q);
//	createSeqList(Q);
//	printSeqList(Q);
//	bin_search(Q,4);
//	printSeqList(Q);
	//x=seq_search(Q,2);
	//cout<<"x-->"<<x<<endl;
//	cout<<"find result: "<<seq_search(Q,2)<<endl;
	////////////////////////////////////
	int a[10]={12,2,33,54,65,76,87,98,5,810};
	BSTree T = NULL;
	for(int i=0;i<10;i++)
	  BST_insert(T,a[i]);
	cout<<"中序遍历二叉树\n";
	BST_order(T);
	cout<<endl;
	BST_delete(T,65);
	BST_delete(T,12);
	BST_order(T);
	cout<<endl;
	return 0;
}
