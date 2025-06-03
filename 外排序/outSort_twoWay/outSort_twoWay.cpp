#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//二路外排序,基于二叉haffman树构建,最优归并树
vector<int> twoWayMerge(vector<int>& p1,vector<int>& p2){//二路合并
    vector<size_t> ptr(2,0);
    vector<int> result;
    result.reserve(p1.size()+p2.size());
    while(ptr[0]<p1.size()&&ptr[1]<p2.size()){
        if(p1[ptr[0]]<=p2[ptr[1]]){
            result.push_back(p1[ptr[0]++]);
        }else{
            result.push_back(p2[ptr[1]++]);
        }
    }
    if(ptr[0]>=p1.size()){//p1空
        for(size_t i=ptr[1];i<p2.size();i++){
            result.push_back(p2[i]);
        }
    }else{
        for(size_t i=ptr[0];i<p1.size();i++){
            result.push_back(p1[i]);
        }
    }
    return result;
}
struct TreeNode{//定义haffman树的节点,包括排序依据为数组的大小,以及该数组
    size_t scale;
    vector<int> data;
    TreeNode(vector<int>& input):scale(input.size()),data(input){};

};
struct TreeNodeCompare{//比较器,实现小顶堆
    bool operator()(const TreeNode& p1,const TreeNode& p2){
        return p1.scale>p2.scale;//当p1的大小更大时返回为True,在优先队列中代表p1排在p2后面
    }
};
class HaffmanTree{
    private:
    vector<int> result;
     priority_queue<TreeNode,vector<TreeNode>,TreeNodeCompare> tree;
    public://初始化输入为多个有序数组,作为二维数组输入
    HaffmanTree(vector<vector<int>>& input){
        for(auto v:input){
            if(!v.empty()){
                tree.push(TreeNode(v));
            }
        }//构建树
    }
    vector<int> mergeSort(){
        if(tree.empty()){
            return {};
        }
        while(tree.size()>1){
            TreeNode first=tree.top();
            tree.pop();
            TreeNode second=tree.top();
            tree.pop();
            vector<int> temp=twoWayMerge(first.data,second.data);
            tree.push(TreeNode(temp));
        }
        return tree.top().data;
    }

};
void printArr(vector<int>& input){
    for(int i:input){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> test{
        {1,3,4,4,6,7},
        {2,2,5,5,6,7,},
        {5,5,6},
        {4,4,5,6,7,9},
        {10,20,30,40,50},
        {11,21,31,41,51,61}
    };
    HaffmanTree ht(test);
    vector<int> result=ht.mergeSort();
    printArr(result);
    return 0;
}
