/*************************************************************************
	> File Name: 4-3.cpp
	> Author: ma6174
	> Mail: ma6174@163.com
	> Created Time: 2016年11月10日 星期四 19时31分23秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include "tree.h"
//若一个节点有左儿子就加一没有就不加
int getTreeDepth(Bitree BT,int &high)
{
	int m,n;
	if(!BT)
    {
        cout<<high<<endl;
		return 0;
    }
	else
	{
            high++;
            cout<<BT->data<<" "<<m<<endl;
		getTreeDepth(BT->lChild,high); //son
		getTreeDepth(BT->rChild,high); //brother


	}
}
int main()
{
    	Bitree T;
	int high=0,num=0;
	 createBiTree(T);
	 PreOrder(T);
	 cout<<endl;
	//high= getTreeDepth2(T,num);
	 getTreeDepth(T,high);
	 cout<<"the tree depth is : "<<high<<endl;
	return 0;
}
