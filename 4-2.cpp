/*************************************************************************
	> File Name: 4-2.cpp
	> Author: ma6174
	> Mail: ma6174@163.com
	> Created Time: 2016年11月09日 星期三 21时28分39秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include "subtree.h"
void countOne(Bitree T,int &num)
{
	if(!T)
		return;
		if(T->lChild&&!T->rChild || !T->lChild&&T->rChild)
		num++;
	countOne(T->lChild,num);

	countOne(T->rChild,num);

}
int main()
{
	int num=0;
	Bitree B;
	createBiTree(B);
	PreOrder(B);
	countOne(B,num);
	cout<<num<<endl;
	return 0;
}
