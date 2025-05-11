#include<iostream>
#include<vector>
using namespace std;
const int INF=1e9;
//Floyd算法实现求每对顶点之间的最短路径，图用vector二维向量储存
void Floyd(const vector<vector<int>>& graph,vector<vector<int>>& dist){
    size_t n=graph.size();
    dist.resize(graph.size(),vector<int>(n));
    for(size_t i=0;i<n;i++){//初始化dist
        for(size_t j=0;j<n;j++){
            if(i==j){
                dist[i][j]=0;//自身到自身距离为0
            }else{
                dist[i][j]=graph[i][j];
            }
        }
    }
    for(size_t k=0;k<n;k++){
        for(size_t i=0;i<n;i++){
            for(size_t j=0;j<n;j++){
                if(dist[i][k]<INF&&dist[k][j]<INF){//i->k,k->j均可达
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                    //更新i->j距离为i直接到j和i经过k再到j的最小值
                }
            }
        }
    }
}
int main(){
    vector<vector<int>> graph={
        {0,INF,2},
        {5,0,8},
        {INF,3,0}
    };
    vector<vector<int>> dist;
    Floyd(graph,dist);
    cout<<"各个顶点对之间的距离："<<endl;
    for(size_t i=0;i<graph.size();i++){
        for(size_t j=0;j<graph.size();j++){
            if(dist[i][j]==INF){
                cout<<"INF\t";
            }else{
                cout<<dist[i][j]<<"\t";
            }
        }
         cout<<endl;
    }
    return 0;
}