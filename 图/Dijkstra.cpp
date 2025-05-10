#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int INF=INT_MAX;
vector<int> Dijkstra(int src,const vector<vector<pair<int,int>>>& graph){//图中pair<int vertex,int weight>,优先队列中pair<int distance,int vertex>
    int n=graph.size();
    vector<int> dist(n,INF);//dist存最短距离
    dist[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//c创建升序(最小堆)优先队列，pq中pair<int distance,int vertex>
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if(d>dist[u]) continue;//dist[v]记录的结果已经够小就跳过
        for(auto [v,w]:graph[u]){//遍历点u的邻接表
            if(dist[u]+w<dist[v]){//通过u到达v即dist[u]+w比直接到达v即dist[v]短，就更新
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main(){
    int n=4;
    vector<vector<pair<int,int>>> graph(n);
    graph[0].emplace_back(1, 4); // 0->1 (权重4)
    graph[0].emplace_back(2, 1); // 0->2 (权重1)
    graph[2].emplace_back(1, 2); // 2->1 (权重2)
    graph[1].emplace_back(3, 1); // 1->3 (权重1)
    graph[2].emplace_back(3, 5); // 2->3 (权重5)
    auto dist=Dijkstra(0,graph);
    for(int i=0;i<n;i++){
        cout<<"Distance to vertex:"<<i<<"is:"<<dist[i]<<endl;
    }
    return 0;

}
