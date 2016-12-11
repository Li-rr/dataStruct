#include <iostream>
 using namespace std;
 #include "linkQueue.h"
 #define INF 65535   //定义无穷大
 #define MaxVerNum 100 //定义最大顶点个数，可自行更改
 int visited[MaxVerNum] ={0};//标志顶点是否被访问
 typedef char ElementType; //定义图中顶点的数据类型
 typedef int cellType; //定义邻接矩阵中数据元素的类型.
 typedef struct GraphAdjMatrix
 {
 	ElementType Data[MaxVerNum];
 	cellType AdjMatrix[MaxVerNum][MaxVerNum];
 	int VerNum;
 	int ArcNum;
 }Graph;
 //////////////////////////
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

 void DFS(Graph  &Gph,int verID,int &Arc_num)
 {
     cout<<Gph.Data[verID-1]<<"\t";//相当于visit（G，verID）
    // cout<<"\nprint success\n";
     visited[verID-1]=1;
     for(int w=0;w<Gph.VerNum;w++)
     {
		 if(Gph.AdjMatrix[verID-1][w])
		 {
			Arc_num++;
		 }
          // cout<<"w-->"<<w<<endl;
         if(Gph.AdjMatrix[verID-1][w]==1&&!visited[w])
         {
             DFS(Gph,w+1,Arc_num);
         }

     }
    // cout<<"this is dfs\n";
 }
 ////////////////////////////////////////////
 //连通分量
 int numOfCC(Graph G,int &Arcnum)
 {
     int i,k=0;
     for(i=0;i<G.VerNum;i++)
         visited[i]=0;
     for(i=0;i<G.VerNum;i++)
         if(!visited[i])
		{
         k++;
         DFS(G,i+1,Arcnum);
         //return k;
	}
		return k;
 }
 void BFS(Graph &G,int verID,int &Arcnum)
 {
    // cout<<"this is BFS\n";
     int u;
     linkQueue Q; //定义一个链队列

     initQueue(Q); //初始化

     cout<<G.Data[verID-1]<<"\n\n"; //访问编号为verID的顶点
     visited[verID-1]=1;  //标记已经访问
     enterQueue(Q,verID); //编号为verID的入队
     ////////////////////////
     while(!queueEmpty(Q))   //队列不为空时，处理顶点
     {
        outQueue(Q,u);  //取队头元素到顶点u，即顶点编号为u
        for(int w=0;w<G.VerNum;w++)
        {
            if(G.AdjMatrix[u-1][w]==1)
            {
                Arcnum++;
            }
            if(G.AdjMatrix[u-1][w]>=1&&G.AdjMatrix[u-1][w]<INF&&!visited[w])
            {
                //cout<<u-1<<"-->"<<w<<endl;
                cout<<G.Data[w]<<"\n";//访问编号为w+1的顶点
                visited[w]=1; //标记w+1已访问
              //  cout<<"w+1-->"<<w+1<<endl<<endl;
                enterQueue(Q,w+1); //编号w+1的

            }
        }
      //  cout<<"u-->"<<u<<endl;
     }
  //   cout<<"BFS is over\n";
 }
 ///////////////////////////////
 //返回值为连通分量数
int BFSTraverse(Graph &G,int verID,int &Arcnum)
{
      int vID;
      int conNum=0; //连通分量数
      for(vID=0;vID<G.VerNum;vID++)
        visited[vID]=0;
      BFS(G,verID,Arcnum);//从指定的顶点verID开始，遍历第一个连通分量
      conNum++;
      for(vID=1;vID<=G.VerNum;vID++)
      {
          if(!visited[vID-1])
          {
              BFS(G,vID,Arcnum);
              conNum++;
          }
      }
    return conNum;
}
int main()
{
    Graph P;
    int num=0;
    initial(P);
    Create(P);
    BFSTraverse(P,1,num);

   // numOfCC(P,num);
    //cout<<endl;
    cout<<"Arcnum-->"<<num<<endl;

    return 0;
}
