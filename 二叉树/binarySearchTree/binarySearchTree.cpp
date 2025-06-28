#include<iostream>
#include<vector>
using namespace std;
 struct TreeNode{
    int key;
    TreeNode* left,*right;
};
int BST_insert(TreeNode* &T,int k){
    if(T==nullptr){
        T=new TreeNode;
        T->key=k;
        T->left=T->right=nullptr;
        return 1;
    }else if(k==T->key){
        return 0;
    }
    else if(k<T->key){//小则向左沉降
        return BST_insert(T->left,k);
    }else{//大则向右沉降
        return BST_insert(T->right,k);
    }
}
void construct_BST(TreeNode* &T,vector<int>&data){
    for(size_t i=0;i<data.size();i++){
        BST_insert(T,data[i]);
    }
}
void inorder(TreeNode*root){
    if(!root) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
int main(){
    vector<int> example={45,24,53,45,12,24};
    TreeNode *BST=nullptr;
    construct_BST(BST,example);
    inorder(BST);
    return 0;
}