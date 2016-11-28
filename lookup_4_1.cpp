#include <iostream>
using namespace std;
typedef int ElemType;
#include "slnode.h"
#include "sequence_table.h"
/*
 *简单顺序查找
 *若找到返回该元素的下标
 *若找不到返回-1
 */
int seq_search(seqList L,ElemType key)
{
    int i = L.listLen-1;
    int flag=0;
    while( L.data[i] != key )
        i--;

    if(L.data[i]==key)
    {
        flag=1;
    }
    if(!flag)
    {
        i=-1;
    }
    cout<<flag<<endl;
    return i;

}
int main()
{
	seqList Q;
	int x;
	initialSeqList(Q);
	createSeqList(Q);
	printSeqList(Q);
	//x=seq_search(Q,2);
	//cout<<"x-->"<<x<<endl;
	cout<<"find result: "<<seq_search(Q,2)<<endl;
	return 0;
}
