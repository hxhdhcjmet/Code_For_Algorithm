#include<iostream>
#include<vector>
#include<queue>
//bfs遍历图，创建过程于dfs相同，层次遍历使用队列
using namespace std;
struct GraphMatrix{//邻接矩阵表示图
    vector<char> vertices;
    vector<bool> visited;
    int vertexnum;
    int edgenum;
    vector<vector<int>> adjMtrix;
    GraphMatrix(int n=9):vertexnum(n),adjMtrix(vertexnum,vector<int>(vertexnum,0)),visited(vertexnum,false),vertices(vertexnum){init();};//接受表示大小的参数并初始化
    void init(){//基于给定的图编写的，所以所有初始化直接完成
        for(int i=0;i<vertexnum;i++){
            vertices[i]=('A'+i);
        }
        //A-B,A-F
        adjMtrix[0][1]=1;
        adjMtrix[0][5]=1;
        //B-C,B-G，B-I
        adjMtrix[1][2]=1;
        adjMtrix[1][6]=1;
        adjMtrix[1][8]=1;
        //C-D,C-I
        adjMtrix[2][3]=1;
        adjMtrix[2][8]=1;
        //D-E,D-G,D-H,D-I
        adjMtrix[3][4]=1;
        adjMtrix[3][6]=1;
        adjMtrix[3][7]=1;
        adjMtrix[3][8]=1;
        //E-F,E-H
        adjMtrix[4][5]=1;
        adjMtrix[4][7]=1;
        //F-G
        adjMtrix[5][6]=1;
        //G-F,G-H
        adjMtrix[6][5]=1;
        adjMtrix[6][7]=1;
        //H-G
        adjMtrix[7][6]=1;
        //对称重置
        for(int i=0;i<vertexnum;i++){
            for(int j=0;j<vertexnum;j++){
                adjMtrix[j][i]=adjMtrix[i][j];
            }
        }
    }
    void bfs(){//广度优先遍历
        queue<int> q;//广度优先遍历借助队列
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int index=q.front();
            q.pop();
            cout<<vertices[index]<<" ";
            for(int i=0;i<vertexnum;i++){
                if(adjMtrix[index][i]==1&&!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    
};
int main(){
    GraphMatrix example(9);
    example.bfs();
    return 0;
}