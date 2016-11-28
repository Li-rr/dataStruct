#define MAXLEN 100
typedef struct sList
{
	ElemType data[MAXLEN];	//定义存储表中元素的数组
	int listLen;			//定义表长度分量
}seqList;

void initialSeqList(seqList &L)
{
	L.listLen=0;
}
void createSeqList(seqList &L)
{
	int i,j;
	cout<<"<--enter seq length-->\n";
	cin>>L.listLen;
	cout<<"\n<--enter seq data-->\n";
	for(i=0;i< L.listLen;i++)
	  cin>>L.data[i];
	cout<<"\n<--create success-->\n";
}
void printSeqList(seqList L)
{
	int i;
	cout<<endl;
	for(i=0;i<L.listLen;i++)
	  cout<<L.data[i]<<" ";
	cout<<"\n<--print success-->\n";
}
int listLength(seqList L)
{
	return L.listLen;
}

void listDelete(seqList &L, int i)
{
	int j;
	if(L.listLen == 0)
	  cout<<"<--error,this is EMPTY!-->\n";
	else
	{
		for(j=i; j < L.listLen; j++)
		{
			L.data[j-1] = L.data[j];
		}
		L.listLen--;
	}
}
