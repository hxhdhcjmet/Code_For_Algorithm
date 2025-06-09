//链表实现
#include<iostream>
using namespace std;
template<typename T>
struct Lnode {
    T data;
    Lnode *next;
    Lnode(T val){
        data=val;
        next=nullptr;
        
    }
};
template<typename T>
class LinkedList{
    public:
    Lnode<T>* head;//头节点
    Lnode<T>* tail;//尾节点
    LinkedList(){
        head=new Lnode<T>(T());//初始化头节点
        tail=head;
    }
    void List_headInsert(){//头插法
        T val;
        cout<<"please input the value of new node(9999 represent stop):"<<endl;
        cin>>val;
        while(val!=9999){
           Lnode<T>* s=new Lnode<T>(val);
            s->next=head->next;
            head->next=s;
            if(tail==head){
                tail=s;
            }
            cout<<"input next val or stop:"<<endl;
            cin>>val;
        }
    }
    void List_tailInsert(){//尾插法
        T val;
        cout<<"please input the value of new node to insert the list by tail_Insert method(9999 represent stop)"<<endl;
        cin>>val;
        while(val!=9999){
            Lnode<T>* s=new Lnode<T>(val);
            tail->next=s;
            tail=s;
            cout<<"input the next val or stop"<<endl;
            cin>>val;
        }
    }
    Lnode<T>* getNode_position(int i){//获取第i个节点的指针
        Lnode<T>* node=head->next;
        if(i==1) return node;//返回第一个节点
        if(i<1) return nullptr;//空返回空指针
        int j=1;
        while(j<i&&node){
            j++;
            node=node->next;
        }
        return node;
    }
    Lnode<T>* getNode_value(T val){//获取值为value的节点
        Lnode<T>* node=head->next;
        while(node&&node->data!=val){
            node=node->next;
        }
        return node;
    }
    void printList(){
        Lnode<T>* curr=head->next;
        while(curr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    void delete_node(int i){//删除第i个位置的节点
        Lnode<T>* node=getNode_position(i-1);
        Lnode<T>* q=node->next;
        node->next=q->next;
        delete q;
    }
    void insertByposition(int i,T newval){//输入插入的位置
        Lnode<T>* node=getNode_position(i-1);
        Lnode<T>* s=new Lnode<T>(newval);
        s->next=node->next;
        node->next=s;
    }
    int getLength(){
        Lnode<T>* curr=head->next;
        int j=0;
        while(curr){
            j++;
            curr=curr->next;
        }
        return j;
    }
};
int main(){
    LinkedList<int> ls;
    ls.List_tailInsert();
    ls.printList();
    cout<<ls.getLength()<<endl;
    ls.insertByposition(3,55);
    ls.printList();
    cout<<ls.getLength()<<endl;
    return 0;
}
