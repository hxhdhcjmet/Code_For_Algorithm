//DSU,并查集，按路径压缩
#include<iostream>
#include<vector>
using namespace std;
class UnionFind{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n,0);//按秩压缩路径，秩初始化为0
        for(int i=0;i<n;i++){
            parent[i]=i;//初始自己的父节点为自己
        }
    }
    int Find(int index){
        while(parent[index]!=index){
            parent[index]=parent[parent[index]];
            index=parent[index];
        }
        return index;
    }
    void Union(int a,int b){
        int roota=Find(a);
        int rootb=Find(b);
        if(roota==rootb) return;
        if(rank[a]<rank[b]){//a的秩小，把a接到b上去
            parent[roota]=rootb;
        }else{
            parent[rootb]=roota;
            if(rank[roota]==rank[rootb]){
                rank[roota]++;
            }
        }
    }
    bool connected(int a,int b){
        int roota=Find(a);
        int rootb=Find(b);
        return roota==rootb;
    }
};
int main(){
    UnionFind uf(5);
    uf.Union(0,1);
    uf.Union(2,3);//0,1连通，2，3连通
    cout<<uf.connected(0,1)<<endl;//1
    cout<<uf.connected(0,2)<<endl;//0
    uf.Union(1,2);//1,2连通
    cout<<uf.connected(0,3)<<endl;//1
    cout<<uf.connected(3,4)<<endl;//0
}