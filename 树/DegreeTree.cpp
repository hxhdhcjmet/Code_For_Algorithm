#include<iostream>
#include<stack>
#include<vector>
using namespace std;
struct DegreeTree{//创建带数据和度数的节点
    int data;
    unsigned int degree;
    DegreeTree():data(-1),degree(0){};
    DegreeTree(int val,unsigned int degree):data(val),degree(degree){};
};
struct TreeNode{//一般的树的节点
    int data;
    TreeNode *child;
    TreeNode *sibling;
    TreeNode():data(-1),child(nullptr),sibling(nullptr){};
    TreeNode(int data):data(data),child(nullptr),sibling(nullptr){};
};
class Tree{
    private:
    TreeNode *root;
    void preorderHelp(TreeNode*node){
        if(!node){
            return;
        }
        cout<<node->data<<" ";
        preorderHelp(node->child);
        preorderHelp(node->sibling);
    }
    public:
    Tree(vector<DegreeTree*> nodeArr,int count){
        if(count<=0||nodeArr.empty()){//不合法情况直接处理
            root=nullptr;
            return;
        }
        stack<TreeNode*> st;
        for(int i=0;i<count;i++){
            TreeNode *temp=new TreeNode(nodeArr[i]->data);
            if(nodeArr[i]->degree==0){//度数为0，叶子节点。入栈
                st.push(temp);
            }else{
                TreeNode *lastchild=nullptr;
                for(int j=0;j<nodeArr[i]->degree;j++){
                    if(st.empty()){//栈空，没有足够元素作为孩子，数据输入数据有问题
                        cout<<"Wrong input!"<<endl;
                        return;
                    }
                    TreeNode *child=st.top();
                    st.pop();
                    if(j==0){//首次处理
                        temp->child=child;
                        lastchild=child;
                    }else{
                        child->sibling=temp->child;
                        temp->child=child;
                        lastchild=child;
                    }
                }
                st.push(temp);
            }
        }
        if(!st.empty()){
            root=st.top();
            st.pop();
        }else{
            root==nullptr;
        }
    }
    void preorderTravel(){
        preorderHelp(root);
        cout<<endl;
    }
};
int main(){
    vector<DegreeTree*> nodeArr = {
        new DegreeTree(5, 0),
        new DegreeTree(6, 0),
        new DegreeTree(2, 2),
        new DegreeTree(7, 0),
        new DegreeTree(3, 1),
        new DegreeTree(4, 0),
        new DegreeTree(1, 3)
    };
    Tree tree(nodeArr,nodeArr.size());
    tree.preorderTravel();
    return 0;
}