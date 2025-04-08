#include<iostream>
#include<stack>
#include<deque>
using namespace std;
struct TreeNode{
    char data;
    TreeNode *lchild,*rchild;
    TreeNode():data('\0'),lchild(nullptr),rchild(nullptr){};
    TreeNode(char data):data(data),lchild(nullptr),rchild(nullptr){};

};
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

};
