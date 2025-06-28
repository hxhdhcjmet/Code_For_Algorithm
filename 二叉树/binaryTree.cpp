#include<iostream>
#include<stack>
#include<deque>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *lchild,*rchild;
    TreeNode():data(-1),lchild(nullptr),rchild(nullptr){};
    TreeNode(int data):data(data),lchild(nullptr),rchild(nullptr){};
};
/*
class BinaryTree{
    private:
    TreeNode *root;
    public:
    BinaryTree():root(new TreeNode()){};
    BinaryTree(int ini):root(new TreeNode(ini)){};
    TreeNode* creatTree(const string& tree,size_t index){
        if(index>=tree.length()) return nullptr;
        char current=tree[index++];
        if(current=='#') return nullptr;
        TreeNode* temp=new TreeNode(current);
        temp->lchild=creatTree(tree,index);
        temp->rchild=creatTree(tree,index);
        return temp;
    }

};*/
TreeNode* creatTree(){
    TreeNode* root=new TreeNode(1);
    root->lchild=new TreeNode(2);
    root->rchild=new TreeNode(3);
    root->lchild->lchild=new TreeNode(4);
    root->lchild->rchild=new TreeNode(5);
    root->lchild->lchild->lchild=new TreeNode(6);
    root->lchild->lchild->lchild->lchild=new TreeNode(7);
    return root;
}
int countDegree0(TreeNode *root){
    if(!root) return 0;
    if(root->lchild==nullptr&&root->rchild==nullptr){
        return 1+countDegree0(root->lchild)+countDegree0(root->rchild);
    }
    return countDegree0(root->lchild)+countDegree0(root->rchild);
}
void countDegree2(TreeNode *root,int &count){
    if(!root) return;
    if(root->lchild&&root->rchild){
        count++;
    }
    countDegree2(root->lchild,count);
    countDegree2(root->rchild,count);
}
int countDegree2_(TreeNode* root){
    if(!root) return 0;
    int count=0;
    if(root->lchild&&root->rchild){
        count++;
    }
    return count+countDegree2_(root->lchild)+countDegree2_(root->rchild);
}
int height(TreeNode *root){
    if(!root) return 0;
    int lh=height(root->lchild);
    int rh=height(root->rchild);
    return 1+max(lh,rh);
}
void preorder(TreeNode*root){//前序遍历
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->lchild);
    preorder(root->rchild);
}
TreeNode* deleteleaf(TreeNode* root){
    if(!root) return nullptr;
    if(root->lchild==nullptr&&root->rchild==nullptr){
        delete root;
        return nullptr;
    }
    root->lchild=deleteleaf(root->lchild);
    root->rchild=deleteleaf(root->rchild);
    return root;
}
int getnodeLevel(TreeNode* root,TreeNode*target,int currlev){
    if(!root) return 0;
    if(root==target){
        return currlev;
    }
    int leftlev=getnodeLevel(root->lchild,target,currlev+1);
    if(leftlev!=0){
        return leftlev;
    }
    return getnodeLevel(root->rchild,target,currlev+1);

}
int main(){
    TreeNode *root=creatTree();
    preorder(root);
    cout<<endl;
    int level=getnodeLevel(root,root->lchild->rchild,1);
    cout<<level<<endl;
    return 0;
}