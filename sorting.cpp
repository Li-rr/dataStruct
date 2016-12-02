#include <iostream>
using namespace std;
#include "sequence_table.h"
void insertSort(seqList &Q)
{
	int i,j,temp;
	for(i=1;i<Q.listLen;i++)
	{
		temp = Q.data[i];
		j = i-1;
		while(Q.data[j]>temp)
		{
			Q.data[j+1]=Q.data[j];
			j=j-1;
		}
		Q.data[j+1]=temp;
	}
}
int main()
{
	seqList Q;
	initialSeqList(Q);
	createSeqList(Q);
	printSeqList(Q);
	insertSort(Q);
	printSeqList(Q);
	cout<<"\n<--over-->\n";
	return 0;
}
