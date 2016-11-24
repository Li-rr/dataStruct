/*************************************************************************
	> File Name: Graph.cpp
	> Author: ma6174
	> Mail: ma6174@163.com
	> Created Time: 2016年11月12日 星期六 12时23分45秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define INF 65535   //定义无穷大
#define MaxVerNum 1000 //定义最大顶点个数，可自行更改
typedef int InfoType;
int visited[MaxVerNum] ={0};//标志顶点是否被访问
typedef char ElementType; //定义图中顶点的数据类型
typedef int cellType; //定义邻接矩阵中数据元素的类型
typedef struct GraphAdjMatrix
{
	ElementType Data[MaxVerNum];
	cellType AdjMatrix[MaxVerNum][MaxVerNum];
	int VerNum;
	int ArcNum;
}Graph;
//////////////////////////
//定义邻接表类型
//边的节点结构
typedef struct ANode
{
       int adjvex; //该边的终点位置
       struct Anode * nextarc;  //指向下一条边的指针
        InfoType info; //该边的相关信息,这里用于存放权值
} ArcNode;
typedef int Vertex;
//邻接表头节点定义
typedef struct Vnode
{
    Vertex data;        //顶点信息
    ArcNode * firstarc; //指向第一条边
}VNode;
typedef VNode AdjList[MaxVerNum];//adjList 是邻接表类型
typedef struct
{
    AdjList adjlist;
    int n,e;//图中的顶点数n和边数e
}ALGraph;
/////////////////////////////////
void MatToList(Graph g,ALGraph * &G)
{
    int i,j;
    ArcNode *p;
    G = new ALGraph;
    for(i=0;i<g.VerNum;i++)
        G->adjlist[i].firstarc=NULL;
    for(i=0;i<g.VerNum;i++)
    {
        for(j=g.VerNum-1;j>=0;j--)
        {
            if(g.AdjMatrix[i][j])
            {
                p=new ArcNode;
                p->adjvex=j;
                //bug
                p->nextarc=G->adjlist[i].firstarc;
                G->adjlist[i].firstarc=p;
            }
            G->n=g.VerNum;
            G->e=g.ArcNum;
        }
    }
}

//初始化
void initial(Graph &Gph)
{
    int i,j;
    Gph.VerNum=0;
    Gph.ArcNum=0;
    for(i=0;i<MaxVerNum;i++)
    {
        Gph.Data[i]=' ';
        for(j=0;j<MaxVerNum;j++)
        {
            Gph.AdjMatrix[i][j]=0;
        }
    }
    cout<<"<--inital success-->"<<endl;
}
//查找当前顶点的编号
int located(Graph Gph,ElementType vernum)
{
	int i, number = -1;
	for(i=0;i<Gph.VerNum;i++)
	{
		if( Gph.Data[i] == vernum)
			 number = i;
	}
	return number;
}
void Create(Graph &Gph)
{
	int i=0,j=0,locatA=0,locatB=0;
	ElementType dataA,dataB;
	////////////////////
	cout<<"enter vertex number: ";
	cin>>Gph.VerNum;
	////////////////////
	cout<<"\nenter vertex's data: ";
	for(i = 0; i<Gph.VerNum;i++)       //输入顶点数据元素
		cin>>Gph.Data[i];
	////////////////////
	//创建邻接矩阵
	cout<<"\n enter line ,end with enter two '.': \n";
	while(true)
    {
            cin>>dataA>>dataB;
            locatA=located(Gph,dataA);
            locatB=located(Gph,dataB);
            cout<<dataA<<"-->"<<locatA<<" "<<dataB<<"-->"<<locatB<<endl;
            Gph.AdjMatrix[locatA][locatB]=1;
            //边条数加一
            Gph.ArcNum++;
            if(dataA=='.'&&dataB=='.')
                break;

    }
	cout<<"<--crate success-->\n";
}

void DFS(Graph  &Gph,int verID)
{
    cout<<Gph.Data[verID-1]<<"\t";//相当于visit（G，verID）
   // cout<<"\nprint success\n";
    visited[verID-1]=1;
    for(int w=0;w<Gph.VerNum;w++)
    {
         // cout<<"w-->"<<w<<endl;
        if(Gph.AdjMatrix[verID-1][w]==1&&!visited[w])
        {
            DFS(Gph,w+1);
        }

    }
   // cout<<"this is dfs\n";
}
//连通分量
int numOfCC(Graph G)
{
    int i,k=0;
    for(i=0;i<G.VerNum;i++)
        visited[i]=0;
    for(i=0;i<G.VerNum;i++)
        if(!visited[i])
    {
        k++;
        DFS(G,i);
        return k;
    }
}

int main()
{
    Graph P;
    initial(P);
    Create(P);

    DFS(P,1);

    cout<<numOfCC(P);
    return 0;
}
