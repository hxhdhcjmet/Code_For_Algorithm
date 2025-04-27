#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX INT_MAX//没有路径的两点之间距离为无穷，计为int最大2^31-1
struct Edge{//Kruskal算法从边开始，因此创建一个边的结构体
    int begin;
    int end;
    int weight;
};
void LessSort(vector<Edge> &p){//从小到大排序
    int n=p.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(p[j].weight>p[j+1].weight){
                Edge temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
int find(const vector<int> &parent,int index){//查找返回合适的位置，返回的是一个可用的位置
    while(parent[index]>0){
        index=parent[index];
    }
    return index;
}
struct GraphMatrix{//邻接矩阵表示图
    vector<char> vertices;
    vector<bool> visited;
    int vertexnum;
    int edgenum;
    vector<vector<int>> adjMatrix;
    GraphMatrix(int n=9):vertexnum(n),visited(n,false),adjMatrix(n,vector<int>(n,MAX)),edgenum(15){
        for(int i=0;i<vertexnum;i++){
            adjMatrix[i][i]=0;//对角线，即自身到自身为0     
    }
    vertices={'A','B','C','D','E','F','G','H','I'};
    init();
}
    void init(){
        //A-B,A-F
        adjMatrix[0][1]=10;
        adjMatrix[1][0]=10;
        adjMatrix[0][5]=11;
        adjMatrix[5][0]=11;
        //B-C,B-G,B-I
        adjMatrix[1][2]=18;
        adjMatrix[2][1]=18;
        adjMatrix[1][6]=16;
        adjMatrix[6][1]=16;
        adjMatrix[1][8]=12;
        adjMatrix[8][1]=12;
        //C-D,C-I
        adjMatrix[2][3]=22;
        adjMatrix[3][2]=22;
        adjMatrix[2][8]=8;
        adjMatrix[8][2]=8;
        //D-E,D-G,D-H,D-I
        adjMatrix[3][4]=20;
        adjMatrix[4][3]=20;
        adjMatrix[3][6]=24;
        adjMatrix[6][3]=24;
        adjMatrix[3][7]=16;
        adjMatrix[7][3]=16;
        adjMatrix[3][8]=21;
        adjMatrix[8][3]=21;
        //E-F,E-H
        adjMatrix[4][5]=26;
        adjMatrix[5][4]=26;
        adjMatrix[4][7]=7;
        adjMatrix[7][4]=7;
        //F-G
        adjMatrix[5][6]=17;
        adjMatrix[6][5]=17;
        //G-H
        adjMatrix[6][7]=19;
        adjMatrix[7][6]=19;
    }
    void Kruskal(){
        vector<Edge> edges;
        for(int i=0;i<vertexnum;i++){
            for(int j=i+1;j<vertexnum;j++){
                if(adjMatrix[i][j]<MAX){//记录边的信息
                    edges.push_back({i,j,adjMatrix[i][j]});
                }
            }
        }
        LessSort(edges);
        vector<int> parent(vertexnum,-1);//初始化parent数组，值全为0
        for(int i=0;i<edgenum;i++){
            int n=find(parent,edges[i].begin);
            int m=find(parent,edges[i].end);
            if(n!=m){//n,m不相等才添加到最小生成树
                parent[n]=m;
                cout<<'('<<n<<','<<m<<')'<<' '<<'('<<vertices[n]<<'-'<<vertices[m]<<')'<<endl;
            }
        }
    }
};
int main(){
    GraphMatrix example(9);
    example.Kruskal();
    return 0;
}
