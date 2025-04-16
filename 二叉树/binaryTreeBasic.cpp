#include<iostream>
#include<stack>
#include<deque>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode{
    char data;
    TreeNode *lchild,*rchild;
    TreeNode():data('\0'),lchild(nullptr),rchild(nullptr){};
    TreeNode(char data):data(data),lchild(nullptr),rchild(nullptr){};

};
class RecursiveTravel{//递归实现
    protected:
 
    int maxDeepth(TreeNode*temp){
        if(temp==nullptr) return 0;
        return max(maxDeepth(temp->lchild),maxDeepth(temp->rchild))+1;
    }

};
class NonRecursiveTravel{//非递归实现
    protected:
    vector<char> BFS(TreeNode*temp_){//队列实现广度优先搜索
        vector<char> result;
        queue<TreeNode*> que;
        que.push(temp_);
        while(!que.empty()){
            TreeNode *temp=que.front();
            que.pop();
            result.push_back(temp->data);
            if(temp->lchild) que.push(temp->lchild);
            if(temp->rchild) que.push(temp->rchild);
        }
        return result;
    }
    vector<char> noRecursivePreorder(TreeNode*temp){//栈实现前序遍历
        vector<char> result;
        stack<TreeNode*> st;
        st.push(temp);
        while(!st.empty()){
            TreeNode*current=st.top();
            st.pop();
            result.push_back(current->data);
            if(current->rchild) st.push(current->rchild);
            if(current->lchild) st.push(current->lchild);//先压右，后压左，保证出来时先左后右
        }
        return result;
    }
    vector<char> nonRecursiveInorder(TreeNode*temp){//栈实现中序遍历
        vector<char> result;
        stack<TreeNode*> st;
        TreeNode *current=temp;
        while(current||!st.empty()){
            while(current){
            st.push(current);
            current=current->lchild;//一直到达最左边
        }
        TreeNode*tem=st.top();//存入栈顶，为最左边最深，然后让current=左最深的右子树
        st.pop();
        result.push_back(tem->data);
        current=tem->rchild;
    }
    return result;
}

    vector<char> nonRecrusivePostorder(TreeNode*temp){//双栈处理，第二个栈收结果，倒过来就是后序遍历
        vector<char> result;
        stack<TreeNode*> st1,st2;
        st1.push(temp);
        while(!st1.empty()){
            TreeNode* current=st1.top();
            st1.pop();
            st2.push(current);
            if(current->lchild) st1.push(current->lchild);
            if(current->rchild) st1.push(current->rchild);
        }
        while(!st2.empty()){
            result.push_back(st2.top()->data);
            st2.pop();
        }
        return result;
    }


};
class BinaryTree:public RecursiveTravel,public NonRecursiveTravel{
    private:
    TreeNode *root;
    TreeNode* creatTree(const string& tree,size_t& index){
       if(index>=tree.size()) return nullptr;
       if(tree[index]=='#'){
        index++;
        return nullptr;
       }
        TreeNode* temp=new TreeNode(tree[index++]);
        temp->lchild=creatTree(tree,index);
        temp->rchild=creatTree(tree,index);
        return temp;
    }
    public:
    BinaryTree():root(nullptr){};
    BinaryTree(char ini):root(new TreeNode(ini)){};
    void buildTree(const string& tree){
        size_t index=0;
        root=creatTree(tree,index);
    }
    void nonrecrusivepreorderTravel(){
        vector<char> result=noRecursivePreorder(root);
        for(auto it=result.begin();it<result.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    void nonrecursiveInorderTravel(){
        vector<char> result=nonRecursiveInorder(root);
        for(auto it=result.begin();it<result.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    void nonrecursivePostorder(){
        vector<char> result=nonRecrusivePostorder(root);
        for(auto it=result.begin();it<result.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    void BFs(){
        vector<char> result=BFS(root);
        for(auto it=result.begin();it<result.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
};
int main(){
    BinaryTree pi;
    pi.buildTree("ABC###DEF##G##");
    pi.nonrecrusivepreorderTravel();
    pi.nonrecursiveInorderTravel();
    pi.nonrecursivePostorder();
    pi.BFs();
    return 0;

}

