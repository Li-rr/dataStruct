/*************************************************************************
	> File Name: 4-1.cpp
	> Author: ma6174
	> Mail: ma6174@163.com
	> Created Time: 2016年11月09日 星期三 19时54分05秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include "subtree.h"
//返回值为节点所在层次
//x为所求节点的值
int flat=0;
void  getSubtreefloat(Bitree BT,elementType x,int num)
{
        cout<<"start\n";
        if(!BT)
        {
            
            return;
        }else
        {
                 num++;
		if(BT->data == x)
			flat=num;	
            getSubtreefloat(BT->lChild,x,num);
            getSubtreefloat(BT->rChild,x,num);
        }
}
int main()
{
	Bitree B;
	int num=0;
	char cs;
	cin>>cs;
	createBiTree(B);
	PreOrder(B);
	cout<<endl;
    getSubtreefloat(B,cs,num);
	cout<<cs<<"--float-->"<<flat<<endl;
	return 0;
}
