#include<iostream>
using namespace std;
const int M=3;//设定B树的阶数M
const int t=3;//最小度约束
struct BtreeNode{
    int keys[2*t-1];//节点数组
    BtreeNode *children[2*t];//子节点指针
    int keyCount;//当前节点关键字个数
    bool isLeaf;//判断当前是否是叶子节点

    BtreeNode(bool leaf){ //叶子节点构造方法
        isLeaf=leaf;
        keyCount=0;
        for(int i=0;i<2*t;i++) children[i]=nullptr;
    }

};

//遍历
void travel(BtreeNode *node){
    if(!node) return;//空树直接返回
    int i;
    for(i=0;i<node->keyCount;i++){
       if(!node->isLeaf){
        travel(node->children[i]);
       }
       cout<<node->keys[i]<<" ";
    }
    if(!node->isLeaf) travel(node->children[i]);//遍历右子树
}

//查找
BtreeNode *search(BtreeNode* node,int key){//在B树node中查找关键字key，最终返回空或key所在B树节点指针
    if(!node) return nullptr;
    int i=0;
    while(i<node->keyCount&&key>node->keys[i]) i++;//当i还在索引范围内且关键字大于当前关键字数组值时，增加索引，使关键字数值递增
    if(i<node->keyCount&&key==node->keys[i]) return node;
    if(node->isLeaf) return nullptr;//当遍历完当前层未找到且当前为叶子，没有下一层时，返回空，查找失败
    return search(node->children[i],key);//同上，但有子树，在最右边的子树中再次查找
}

//分裂子节点
void splitChild(BtreeNode* parent ,int i,BtreeNode* y){
    BtreeNode* z=new BtreeNode(y->isLeaf);
    z->keyCount=t-1;//y后半部分放在z中，有M/2-1个关键字，下标从0到M/2-2
    
//将分裂节点y后部分分到z上
    for(int j=0;j<t-1;j++){
        z->keys[j]=y->keys[j+t];
    }
    //移动子节点指针
    if(y->isLeaf){
    for(int j=0;j<t;j++){
        z->children[j]=y->children[j+t];
       }
    }
    int median=y->keys[t-1];//将要放到父节点中去的关键字值
    y->keyCount=t-1;

    //父节点腾出位值
    for(int j=parent->keyCount;j>=i+1;j--){
        parent->children[j+1]=parent->children[j];
    }
    parent->children[i+1]=z;


    for(int j=parent->keyCount-1;j>=i;j--){
        parent->keys[j+1]=parent->keys[j];
    }
    parent->keys[i]=median;//第i个位置换为median
    parent->keyCount++;
}

//插入非满节点
void insertNotFull(BtreeNode* node,int key){
    int i=node->keyCount-1;
    if(node->isLeaf){//当是叶子节点时
        while(i>=0&&node->keys[i]>key){
            node->keys[i+1]=node->keys[i];
            i--;
        }
        node->keys[i+1]=key;
        node->keyCount++;
    }else{//不是叶子节点，找合适的子节点
        while(i>=0&&node->keys[i]>key){
            i--;
        }
        i++;//子节点所在下标
        if(node->children[i]->keyCount==2*t-1){//子节点满了，分裂
            splitChild(node,i,node->children[i]);
            if(key>node->keys[i]){
                i++;//如放到第i个位置的数比key小，则key会放在第i个关键字的右边一个区间
            }
        }
        insertNotFull(node->children[i],key);
    }
}
void insert(BtreeNode* &root,int key){//插入
    if(!root){//插入节点为空，创建该节点
        root =new BtreeNode(true);
        root->keyCount=1;
        root->keys[0]=key;
        return;
    }
    if(root->keyCount==2*t-1){//满了就分裂
        BtreeNode* nr=new BtreeNode(false);
        nr->children[0]=root;//创建新的根nr
        splitChild(nr,0,root);//root中间的值上升到新节点nr的keys[0]位置
        int i=0;
        if(nr->keys[0]<key) i++;
        insertNotFull(nr->children[i],key);
        root=nr;
    }else{
        insertNotFull(root,key);//没有满，直接插入root中
    }
}
int main(){
    BtreeNode* root=nullptr;
    int exampleKey[]={1,3,5,7,9,2,4,6,8,10};
    for(int key:exampleKey){
        insert(root,key);
    }
    cout<<"travel start"<<endl;
    travel(root);
    cout<<endl;
    cout<<"travel finish"<<endl;
    insert(root,0);
    travel(root);
    return 0;
}