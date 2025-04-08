#include<iostream>
#include<stack>
#include<deque>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *lchild,*rchild;
    TreeNode():data(0),lchild(nullptr),rchild(nullptr){};
    TreeNode(int data):data(data),lchild(nullptr),rchild(nullptr){};

};
class BinaryTree{
    private:
    TreeNode *root;
    public:
    BinaryTree():root(new TreeNode()){};
    BinaryTree(int ini):root(new TreeNode(ini)){};
    TreeNode* creatTree(){
        
    }

};
