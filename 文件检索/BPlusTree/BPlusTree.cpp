#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int M=4;
struct BPlusNode{
    bool isleaf;
    vector<int> key;
    vector<BPlusNode*> children;
    BPlusNode* next;//叶子节点使用，数据全部储存在叶子中，链表形式
    BPlusNode(bool leaf=false):isleaf(leaf),next(nullptr){};
};
class BPlusTree{//创建B+树类
    private:
    BPlusNode* root;
    public:
    BPlusTree(){
        root=new BPlusNode(true);
    }
    bool search(int key){
        BPlusNode*curr=root;
        while(!curr->isleaf){
            int i=upper_bound(curr->key.begin(),curr->key.end(),key)-curr->key.begin();
            curr=curr->children[i];
        }
        return find(curr->key.begin(),curr->key.end(),key)!=curr->key.end();//找到返回对应迭代器，否则返回end
    }
    void rangeQuery(int low,int high){
        //查询low~high范围内元素
        BPlusNode* curr=root;
        while(!curr->isleaf){
            curr=curr->children[0];
        }//左下降到叶子节点开头位置
        while(curr){
            for(int val:curr->key){
                if(val>=low&&val<=high){
                    cout<<val<<" ";
                }
                if(val>high) return;
            }
            curr=curr->next;
        }
        cout<<endl;
    }
    void printLeaves(){
        BPlusNode*curr=root;
        while(!curr->isleaf) curr=curr->children[0];
        while(curr){
            for(int val:curr->key){
                cout<<val<<" ";
            }
            curr=curr->next;
        }
        cout<<endl;
    }
    void insert(int key){
        BPlusNode* newChild=nullptr;
        int newKey;
        bool split=insertInternal(root,key,newChild,newKey);
        if(split){
            BPlusNode *newRoot=new BPlusNode(false);
            newRoot->key.push_back(newKey);
            newRoot->children.push_back(root);
            newRoot->children.push_back(newChild);
            root=newRoot;
        }
    }
    private:
    bool splitLeaf(BPlusNode* node,BPlusNode* &newNode,int& newkey){
        //叶子节点分裂，newnode为新节点，继承node的后半部分，newkey提升到父节点
        int mid=node->key.size()/2;//获取中间节点的位置
        newNode=new BPlusNode(true);
        newNode->key.assign(node->key.begin()+mid,node->key.end());
        node->key.erase(node->key.begin()+mid,node->key.end());
        newNode->next=node->next;
        node->next=newNode;
        newkey=newNode->key[0];
        return true;
    }

    bool splitInternal(BPlusNode* node,BPlusNode* &newNode,int& newkey){
        //内部节点分裂
        int mid=node->key.size()/2;
        newNode=new BPlusNode(false);
        newkey=node->key[mid];
        newNode->key.assign(node->key.begin()+mid+1,node->key.end());
        newNode->children.assign(node->children.begin()+mid+1,node->children.end());
        node->key.erase(node->key.begin()+mid,node->key.end());
        node->children.erase(node->children.begin()+mid+1,node->children.end());
        return true;
    }
    bool insertInternal(BPlusNode* node,int key, BPlusNode* &newNode,int& newkey){
        //给定节点node，插入值为key
        if(node->isleaf){
            //如果node是叶子节点，那么插入位置就是该叶子
            auto pos=lower_bound(node->key.begin(),node->key.end(),key);
            node->key.insert(pos,key);
            if((int)node->key.size()<M) return false;//叶子节点插入key后没有超出范围，不用分裂
            return splitLeaf(node,newNode,newkey);
        }
        //如果不是叶子，则需要一路往下找到对应得叶子节点
        int i=upper_bound(node->key.begin(),node->key.end(),key)-node->key.begin();
        BPlusNode* child=node->children[i];
        BPlusNode* newChild=nullptr;
        int midKey=0;
        bool split=insertInternal(child,key,newChild,midKey);//一直往下找
        if(split){
            //找到叶子并插入成功，分裂完成，新的子节点为newChild,中间值为midKey
            node->key.insert(node->key.begin()+i,midKey);
            node->children.insert(node->children.begin()+i+1,newChild);
            if((int)node->key.size()>=M){
                return splitInternal(node,newNode,newkey);
            }
        }
        return false;
    }
};
int main(){
    BPlusTree tree;
    vector<int> example={9,7,6,5,4,3,1,23,45,3};
    for(int val:example) tree.insert(val);
    cout<<"leaf node:"<<endl;
    tree.printLeaves();
    cout<<"over"<<endl;
    cout<<"Query range from 11 to 50"<<endl;
    tree.rangeQuery(11,50);
    cout<<"over"<<endl;
    return 0;

}