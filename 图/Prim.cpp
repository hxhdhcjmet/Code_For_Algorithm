#include<iostream>
#include<vector>
using namespace std;
#define MAX INT_MAX//没有路径的两点之间距离为无穷，计为int最大2^31-1
struct GraphMatrix{//邻接矩阵表示图
    vector<char> vertices;
    vector<bool> visited;
    int vertexnum;
    int edgenum;
    vector<vector<int>> adjMatrix;
    GraphMatrix(int n=9):vertexnum(n),visited(n,false),adjMatrix(n,vector<int>(n,MAX)){
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
    void Prim(){
        vector<int> weight(vertexnum,MAX);//记录权值,初始全为MAX,已经加入最小生成树的weight计为0，之后将不会再次加入
        vector<int> vexindex(vertexnum,0);//记录父子关系，初始全部计为0
        int j,k,min;
        //从第一个顶点开始
        weight[0]=0;
        vexindex[0]=0;
        for(int i=1;i<vertexnum;i++){
            weight[i]=adjMatrix[0][i];
        }
        
        for(int i=0;i<vertexnum-1;i++){
            k=-1;
            min=MAX;
            for(j=0;j<vertexnum;j++){//遍历
                if(weight[j]!=0&&weight[j]<min){
                    min=weight[j];
                    k=j;//找最小权值
                }
            }
            if(k==-1) break;//未找到，直接退出
            //cout<<vexindex[k]<<','<<k<<endl;//记录哪些顶点连接起来了
            cout<<vertices[vexindex[k]]<<','<<vertices[k]<<endl;
            weight[k]=0;//标记为已经加入最小生成树，后续不会重复加入
            for(j=0;j<vertexnum;j++){//找能与新的顶点相连的点
                if(weight[j]!=0&&adjMatrix[k][j]<weight[j]){//有比weight小的就替换
                    weight[j]=adjMatrix[k][j];
                    vexindex[j]=k;//添加两个点之间的关系，表示能相连
                }
            }
        }
}
};
int main(){
    GraphMatrix example(9);
    example.Prim();
    return 0;
}

