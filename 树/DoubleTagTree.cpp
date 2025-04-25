#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct DualTagTree{//双标记节点，构造成数组，0表示有，1表示无
    int data;
    int ltag;
    int rtag;
};
struct TreeNode{
    int data;
    TreeNode *child;
    TreeNode *sibling;
    TreeNode():data(-1),child(nullptr),sibling(nullptr){};
    TreeNode(int val):data(val),child(nullptr),sibling(nullptr){};
    void setVal(int data){
        this->data=data;
    }
    void setSibling(TreeNode *sibling){
        this->sibling=sibling;
    }
    void setChild(TreeNode *child){
        this->child=child;
    }
};
class Tree{
    private:
    TreeNode*root;
    void preorderHelp(TreeNode *node){
        if(!node) return;
        cout<<node->data<<" ";
        preorderHelp(node->child);
        preorderHelp(node->sibling);
    }
    public:
    Tree(vector<DualTagTree*> nodeArr,int count){//创建树，用栈来处理右兄弟关系
        if(count==0||nodeArr.empty()){
            root=nullptr;
            return;
        }
        stack<TreeNode*> st;
        root=new TreeNode(nodeArr[0]->data);
        TreeNode *pointer=root;
        for(int i=0;i<count-1;i++){//计数count-1次循环，最后一个节点一定没有孩子和兄弟
          DualTagTree* current=nodeArr[i];
          if(current->rtag==0){//有右兄弟，压入栈
            st.push(pointer);
          }
          //创建下一个节点
          TreeNode *temp=new TreeNode(nodeArr[i+1]->data);
          if(current->ltag==0){//有孩子，下一个即是孩子
            pointer->setChild(temp);
          }else{//无左孩子，下一个是栈顶的右兄弟
            if(!st.empty()){
                TreeNode *parent=st.top();
                st.pop();
                parent->setSibling(temp);
            }
          }
          pointer=temp;
        }
        //最后一个节点不用判断，直接处理
        if(count>0){//判断确保-1合法
        pointer->setVal(nodeArr[count-1]->data);
        pointer->setChild(nullptr);
        pointer->setSibling(nullptr);
        }
    }
    void preorderTravel(){
        preorderHelp(root);
        cout<<endl;
    }
};
int main(){
    vector<DualTagTree *> nodeArr = {
        new DualTagTree{1, 0, 1}, // 根节点，有左孩子，有右兄弟
        new DualTagTree{2, 0, 0}, // 有右兄弟
        new DualTagTree{5, 1, 0}, // 无右兄弟
        new DualTagTree{6, 1, 1},// 无右兄弟
        new DualTagTree{3, 0, 0}, // 无右兄弟
        new DualTagTree{7, 1, 1},
        new DualTagTree{4, 1, 1} // 有左孩子，有右兄弟
    };
    Tree tree(nodeArr,7);
    cout<<"preorder travel tree result:"<<endl;
    tree.preorderTravel();
    return 0;
}