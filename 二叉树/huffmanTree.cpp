#include<iostream>
#include<vector>
using namespace std;
struct huffmanTreeNode{
    char data;
    unsigned int fre;
    huffmanTreeNode *left,*right;
    huffmanTreeNode(char data,unsigned int fre):data(data),fre(fre),left(nullptr),right(nullptr){};
    huffmanTreeNode(unsigned int fre,huffmanTreeNode *left,huffmanTreeNode *right):data('\0'),fre(fre),left(left),right(right){};
    //构建合并节点的，因为合并节点的值不重要，直接赋值为‘\0’
};
class MinHeap{
    private:
    vector<huffmanTreeNode*> heap;
    void swap(int i,int j){
        huffmanTreeNode* temp=heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
    }
    void siftUp(int index){
        while(index>0){
            int parent=(index-1)/2;
            if(heap[parent]->fre<heap[index]->fre) break;
            swap(index,parent);
            index=parent;
        }
    }
    void siftDown(int index){
        int n=heap.size();
        while(true){
            int left=2*index+1;
            int right=2*index+2;
            int smallest=index;
            if(left<n&&heap[smallest]->fre>heap[left]->fre) smallest=left;
            if(right<n&&heap[smallest]->fre>heap[right]->fre) smallest=right;
            if(smallest!=index){
                swap(smallest,index);
                index=smallest;
            }else{
                break;
            }
        }
    }
    public:
    void insert(huffmanTreeNode *node){
        heap.push_back(node);
        siftUp(heap.size()-1);
    }
    int size() const{
        return heap.size();
    }
    huffmanTreeNode* RemoveMin(){
        if(heap.empty()) return nullptr;
        huffmanTreeNode *min=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        siftDown(0);
        return min;
    }
    huffmanTreeNode* buildHuffmanTree(char data[],unsigned int fre[],int size){
        MinHeap pi;
        for(int i=0;i<size;i++){
            huffmanTreeNode *temp=new huffmanTreeNode(data[i],fre[i]);
            pi.insert(temp);
        }
        while(pi.size()>=2){//有两个以上的节点都可以合成
            huffmanTreeNode *left=pi.RemoveMin();
            huffmanTreeNode *right=pi.RemoveMin();
            huffmanTreeNode *parent=new huffmanTreeNode(left->fre+right->fre,left,right);
            pi.insert(parent);
        }
        return pi.RemoveMin();
    }
    void printcode(huffmanTreeNode *root,const string& prefix){
        if(root==nullptr) return;
        if(root->left==nullptr&&root->right==nullptr){//叶子节点输出值
            cout<<root->data<<":"<<prefix<<endl;
        }
        printcode(root->left,prefix+"0");
        printcode(root->right,prefix+"1");
    }
    void freeTree(huffmanTreeNode *root){
        if(root==nullptr) return;
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
};
int main(){
    char data[]={'a','b','c','d','e','f','g'};
    unsigned int fre[]={15,2,6,5,20,10,18};
    int size=sizeof(data)/sizeof(data[0]);
    MinHeap test;
    huffmanTreeNode *temp;
    temp=test.buildHuffmanTree(data,fre,size);
    cout<<"huffmantree code:"<<endl;
    test.printcode(temp,"");
    test.freeTree(temp);
    return 0;
    

}