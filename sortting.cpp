#include <iostream>
using namespace std;
typedef int ElemType;
#include "sequence_table.h"
/*
 *直接插入排序 
 */
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
//直接插入排序，从大到小
void insertSort2(seqList &Q){
	int i,j;
	int temp;

	for(i=1; i < Q.listLen; i++){
		for(j=i; j>0; j--){
			if(Q.data[j] > Q.data[j-1]){
				temp = Q.data[j-1];
				Q.data[j-1] = Q.data[j];
				Q.data[j] = temp;
			}
		}
	}
}
/*
 *快速排序
 */
void quicksort(seqList &Q,int left,int right )
{
	int i,j,t,temp;
	if(left>right)
	  {
		cout<<"left > right"<<endl;
		return;
	  }
	temp = Q.data[left];
	i = left;
	j = right;
	while(i != j)
	{
		//从右向左
		while( Q.data[j] >= temp && i<j )
		  j--;
		//从左向右
		while( Q.data[i] <= temp && i<j )
		  i++;
	//	while( Q.data[j] >= temp && i<j)
	//	  j--;
		//交换
		if(i<j)
		{
			t = Q.data[i];
			Q.data[i] = Q.data[j];
			Q.data[j] = t;
		}
	}

	//归位
	Q.data[left] = Q.data[i];
	Q.data[i] = temp;
	quicksort(Q,left,i-1);
	quicksort(Q,i+1,right);
	return;
}
int main()
{
	seqList Q;
	initialSeqList(Q);
	createSeqList(Q);
	printSeqList(Q);
//	insertSort(Q);
    quicksort(Q,0,Q.listLen-1);
	printSeqList(Q);
	cout<<"\n<--over-->\n";
	return 0;
}
