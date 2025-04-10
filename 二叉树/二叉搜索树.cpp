#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode():data(0),lchild(nullptr),rchild(nullptr){};
    TreeNode(const int data):data(data),lchild(nullptr),rchild(nullptr){};
};
class BinarySearchTree{
    public:TreeNode* root;
    BinarySearchTree():root(nullptr){};
    BinarySearchTree(const int data):root(new TreeNode(data)){};
    void insert(int val){
        if(root==nullptr){
            root=new TreeNode(val);
            return;
        }
        TreeNode* current=root;
        while(current!=nullptr){
            if(val==current->data){
                return;
            }
            else if(val<current->data){
                if(current->lchild==nullptr){
                    current->lchild=new TreeNode(val);
                    return;
                }else{
                    current=current->lchild;
                }
            }
            else{
                if(current->rchild==nullptr){
                    current->rchild=new TreeNode(val);
                    return;
                }
                else{
                    current=current->rchild;
                }
            }
        }
    } 
    void inorder(TreeNode* node){
        if(node==nullptr){
            return;
        }
        inorder(node->lchild);
        cout<<node->data<<" ";
        inorder(node->rchild);
    }
    void buildTree(vector<int>& value ){
        root=nullptr;
        for(int data:value){
            insert(data);
        }
    }
    /*void deleteNode(int val){
        if(root==nullptr){
           return;
        }
        TreeNode* temp,*tempparrent;
        TreeNode* parrent=nullptr;
        TreeNode* current=root;
        //current存要删除的节点，parrent放current的父节点
        //寻找待删除的节点
        while(current!=nullptr){
            if(val<current->data){
                parrent=current;
                current=current->lchild;
            }
            else if(val>current->data){
                parrent=current;
                current=current->rchild;
            }
            else if(val==current->data){//找到
                if(current->lchild==nullptr){
                    temp=current->rchild;
                    break;
                }else{//左不空，找左子树中序周游的最后一个节点
                    temp=current->lchild;
                    while(temp->rchild!=nullptr){
                        tempparrent=temp;
                        temp=temp->rchild;
                    }//获得了temp
                    break;
                }
        }
    }
    tempparrent->rchild=temp->lchild;
    temp->lchild=current->lchild;
    temp->rchild=current->rchild;
    if(parrent==nullptr){
        root=temp;
    }
    else if(parrent->lchild==current){
        parrent->lchild=temp;
    }
    else parrent->rchild=temp;
    delete current;
    current=nullptr;
    return;
    }*/
   
   void deleteNode(const int val){
    if(root==nullptr) return;
    TreeNode *current=root;
    TreeNode *parrent=nullptr;
    while(current!=nullptr&&current->data!=val){
        parrent=current;
        if(val<current->data){
            current=current->lchild;
        }else {
            current=current->rchild;
        }
    }//找到待删除节点
    if(current==nullptr){
        return;//待删除节点不存在
    }
    if(current->lchild==nullptr){
        TreeNode* temp=current->rchild;
        delete current;
        if(parrent==nullptr){
            root=temp;
        }else if(parrent->lchild==current){
            parrent->lchild=temp;
        }else{
            parrent->rchild=temp;
        }
        return;//左子树为空，直接把右子树接过去
    }else if(current->lchild!=nullptr){
        TreeNode *temp=current->lchild;
        TreeNode *tempparrent=current;
        while(temp->rchild!=nullptr){
            tempparrent=temp;
            temp=temp->rchild;
        }//左不为空，右沉到最大值
        if(tempparrent==current){
            tempparrent->lchild=temp->lchild;
        }
        else{
            tempparrent->rchild=temp->lchild;
        }//temp即为找到的右最大值，是要用来代替被删除的元素
        temp->lchild=current->lchild;
        temp->rchild=current->rchild;
        if(parrent==nullptr){
            root=temp;
        }else if(parrent->lchild==current){
            parrent->lchild=temp;
        }else{
            parrent->rchild=temp;
        }
        delete current;
        current=nullptr;
        return;
    }

   }

 
    
};
int main(){
    vector<int> val={4,5,9,8,3,2};
    BinarySearchTree pi;
    pi.buildTree(val);
    pi.inorder(pi.root);
    cout<<endl;
    pi.deleteNode(2);
    pi.inorder(pi.root);
    return 0;
}