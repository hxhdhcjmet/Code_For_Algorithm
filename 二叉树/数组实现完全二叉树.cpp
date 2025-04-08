#include<iostream>
#include<vector>
using namespace std;
class ArrayBinaryTree{
    private:
    vector<int> tree;
    public:
    void insert(int data){
        tree.push_back(data);
    }
    int getParent(int index){
        if(index<=-1||index>=tree.size()) return -1;
        return (index-1)/2;//返回父节点的下标
    }
    int getLeftChild(int index){
        int lindex=index*2+1;
        return (lindex<tree.size()) ? lindex:-1;//获取左子树下标
    }
    int getRightChild(int index){
        int rindex=index*2+2;
        return (rindex<tree.size()) ? rindex:-1;//获取右子树下标
    }
    void preorderHelp(int index){
        if(index<=-1||index>tree.size()) return;
        cout<<tree[index]<<" ";
        preorderHelp(getLeftChild(index));
        preorderHelp(getRightChild(index));
    }//构造前序遍历辅助函数
    void preorder(){
        preorderHelp(0);
        cout<<endl;
    }//创造前序接口
    bool isLeaf(int index){
        return 2*index+1>=tree.size();//左子树不存在即为叶子节点；
    }
    size_t size(){
        return tree.size();
    }
    int getValue(int index){
        if(index<=-1||index>=tree.size()){
            throw out_of_range("index out of range");
        }
        return tree[index];
    }
};
int main(){
    ArrayBinaryTree p;
    for(int i=0;i<5;i++){
        p.insert(i+1);
    }
    p.preorder();
    return 0;
}