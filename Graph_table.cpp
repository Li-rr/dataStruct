#include <iostream>
using namespace std;
#include "linkQueue.h"
#define MaxVerNum 30
int visited[MaxVerNum]= {0};
typedef int infoType;
typedef char ElemtType;//定义图中的数据类型
//////////////////////////////
typedef struct eNode
{
    int adjVer;
    infoType eInfo;
    struct eNode * next; //下一个结点
}  EdgeNode;
typedef struct vNode        //顶点表
{
    ElemtType data;
    EdgeNode * firstEdge;
} VerNode;
typedef struct GraphAdjLinkList  //图的整体结构
{
    VerNode VerList[MaxVerNum];
    int VerNum;
    int ArcNum;
} Graph;
int located(Graph G,ElemtType data);
void initial(Graph &G)
{
    G.VerNum=0;
    G.ArcNum=0;
    for(int i=0; i<MaxVerNum; i++)
    {
        G.VerList[i].data=-1;
        G.VerList[i].firstEdge=NULL;
    }
    cout<<"<--initial success-->\n";
}
void creatGraph(Graph &G)
{
    int i,j,k;
    ElemtType v1,v2;
    EdgeNode * p;
    cout<<"enter VerNum and ArcNum : ";
    cin>>G.VerNum;
    /////////////////////////////////////////
    cout<<endl<<"enter VerNum data : \n";
    for( i=0; i<G.VerNum; i++)
    {
        cin>>G.VerList[i].data;
        G.VerList[i].firstEdge=NULL;
    }
    ////////////////////////////////////////
    //读边
    // while(true)
//   for(int k=0;k<G.ArcNum;k++)
    while(true)
    {
        cout<<"enter two VerNum with edge : "<<endl;
        cin>>v1>>v2;
        i = located(G,v1);
        j = located(G,v2);
        cout<<i<<"-->"<<G.VerList[i].data<<" "<<j<<"-->"<<G.VerList[j].data<<endl;
        if(v1=='.'&&v2=='.')
            break;
//        //////////
        p = new EdgeNode;
        p ->adjVer = j;
        p ->next = G.VerList[i].firstEdge;
        G.VerList[i].firstEdge=p;
        G.ArcNum++;

    }
    cout<<"<--create success-->\n";
}
/////////////////////////////////////////////
//基于邻接表
void DFS(Graph &G,int verID)
{
    cout<<G.VerList[verID].data<<" ";
    visited[verID]=1;
    EdgeNode * p;
    p = G.VerList[verID].firstEdge;
    while(p)
    {
        if(!visited[(p->adjVer)])
            DFS(G,(p->adjVer));
        p = p ->next;

    }
}
int DFSTraverse(Graph &G,int verID)
{
    int Vid;
    int conNum=0;
    for(Vid=0; Vid<G.VerNum; Vid++)
        visited[Vid]=0;
    DFS(G,verID);
    conNum++;
    for(Vid=0; Vid<G.VerNum; Vid++)
    {
        if(!visited[Vid])
        {
            DFS(G,Vid);
            conNum++;
        }
    }
    return conNum;
}
void BFS(Graph G,int verID)
{
    int u;
    EdgeNode * p;
    linkQueue Q;
    initQueue(Q);
    cout<<G.VerList[verID-1].data<<" ";
    visited[verID-1]=1;
    enterQueue(Q,verID);
    while(!queueEmpty(Q))
    {
        outQueue(Q,u);
        p = G.VerList[u-1].firstEdge;
        while(p)
        {
            if(!visited[(p->adjVer)])
            {
                cout<<G.VerList[p->adjVer].data<<" ";
                visited[p->adjVer]=1;
                enterQueue(Q,p->adjVer+1);
            }
            p = p->next;
        }
    }
}
void print(Graph G)
{
    EdgeNode * p;
    int i=0;
    //for(int i=0;i<G.VerNum;i++)
    {

        cout<<G.VerList[i].data<<" ";
        p = G.VerList[i].firstEdge;
        while(p)
        {
            cout<<G.VerList[p->adjVer].data<<" -";
            p = p->next;
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"<--start main-->\n";
    Graph G;
    initial(G);
    creatGraph(G);
    cout<<endl;
    //print(G);
    //DFS(G,0);
    BFS(G,1);
    // DFSTraverse(G,1);
    cout<<"\n<--over main-->\n";
}
//int located(Graph G,ElemtType data)
//{
//    int loc=-1;
//    for(int i=0; i<G.VerNum; i++)
//    {
//        if(G.VerList[i].data==data)
//        {
//            loc=i;
//            break;
//        }
//    }
//    return loc;
//}
int located(Graph G,ElemtType data)
{
    int key=-1,i=0;
    while(G.VerList[i].data != data&& i!=G.VerNum)
    {
        i++;
    }
    key=i;
    return key;
}

