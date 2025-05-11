#include<iostream>
#include<vector>
const int INF=1e9;
using namespace std;
class Dist{
    public:
    vector<vector<int>> distance;//存距离
    vector<vector<int>> path;//存前一个节点,即
    Dist(int n):distance(n,vector<int>(n)),path(n,vector<int>(n)){};
    Dist()=default;
};
void Floyd_WithPath(const vector<vector<int>>& graph,Dist& dist){
    size_t n=graph.size();
    dist.distance.resize(n,vector<int>(n));
    dist.path.resize(n,vector<int>(n));
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){//初始化dist
            if(i==j){
                dist.distance[i][j]=0;
                dist.path[i][j]=i;//自身到自身距离为0，前一个也为自身
            }else{
                dist.distance[i][j]=graph[i][j];
                if(dist.distance[i][j]==INF){//距离为INF不可达
                    dist.path[i][j]=-1;
                }else{
                    dist.path[i][j]=i;
                }
            }
        }
    }
    //核心算法
    for(size_t k=0;k<n;k++){
        for(size_t i=0;i<n;i++){
            for(size_t j=0;j<n;j++){
                if(dist.distance[i][k]<INF&&dist.distance[k][j]<INF){
                    if(dist.distance[i][j]>dist.distance[i][k]+dist.distance[k][j]){
                        dist.distance[i][j]=dist.distance[i][k]+dist.distance[k][j];
                        dist.path[i][j]=dist.path[k][j];//经过k更小就更新距离distance和路径path
                    }
                }
            }
        }
    }
}
void printpath(int i,int j,const vector<vector<int>>& path){
    if(i==j){
        cout<<i;
        return;
    }
    if(path[i][j]==-1){
        cout<<"no path";
        return;
    }
    printpath(i,path[i][j],path);
    cout<<"->"<<j;
}
int main(){
    vector<vector<int>> graph={
        {0,INF,2},
        {5,0,8},
        {INF,3,0}
    };
    Dist dist;
    Floyd_WithPath(graph,dist);
    cout<<"距离矩阵:"<<endl;
    for(size_t i=0;i<graph.size();i++){
        for(size_t j=0;j<graph.size();j++){
            if(dist.distance[i][j]==INF) cout<<"INF\t";
            else cout<<dist.distance[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"路径显示:"<<endl;
    for(size_t i=0; i<graph.size();i++){
        for(size_t j=0;j<graph.size();j++){
            if(i==j||dist.distance[i][j]==INF) continue;//自身到自身以及不可达就不输出
            cout<<i<<"到"<<j<<":";
            printpath(i,j,dist.path);
            cout<<endl;
        }
    }
    return 0;
}