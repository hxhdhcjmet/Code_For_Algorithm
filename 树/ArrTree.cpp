#include<iostream>
#include<vector>
using namespace std;
class Tree{
    private:
    struct node{
    int data;
    vector<int> child;
    node(int val):data(val){}
    };
    vector<node> nodes;
    int rootindex;
    public:
    Tree():rootindex(-1){}
    void creatRoot(int data){
        if(rootindex==-1){
            nodes.emplace_back(data);
            rootindex=nodes.size()-1;
        }//创建根
    }
    int getRootIndex() const{
        return rootindex;
    }//返回根节点坐标
    void insertChild(int parentInd,int data){
        if(parentInd<0||parentInd>=nodes.size()){
            return;//如果父节点不合法，直接返回
        }
        int newInd=nodes.size();
        nodes.emplace_back(data);
        nodes[parentInd].child.push_back(newInd);
    }//插入孩子
    const vector<int>& getChild(int parentind){//返回parentind下标对应节点的孩子列表
        if(parentind<0||parentind>=nodes.size()){
            static vector<int> empty;
            return empty; 
        }
        return nodes[parentind].child;
    }
    int getData(int index) const{
        if(index<0||index>=nodes.size()){
            return -1;//不合理位置返回-1
        }
        return nodes[index].data;
    }
    void preorderTravel(int index){//前序遍历树
        if(index<0||index>=nodes.size()){
            return;
        }
        cout<<nodes[index].data<<" ";
        for(int i:nodes[index].child){
            preorderTravel(i);
        }

    }
};
int main(){
    Tree tree;
    tree.creatRoot(1);
    int rootIndex=tree.getRootIndex();
    tree.insertChild(rootIndex,2);
    tree.insertChild(rootIndex,3);
    tree.insertChild(rootIndex,4);
    tree.insertChild(1,5);
    tree.insertChild(1,6);
    tree.preorderTravel(rootIndex);
    return 0;

}