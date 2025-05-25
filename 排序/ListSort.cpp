#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr){};
};
ListNode* merge(ListNode *l1,ListNode *l2){//合并两个链表
    ListNode dummy(0);
    ListNode *tail=&dummy;
    while(l1&&l2){
        if(l1->val<l2->val){
            tail->next=l1;
            l1=l1->next;
        }else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    //扫尾
    tail->next=(l1)?l1:l2;//l1不为空，则说明省l1，接上，否则接上l2
    return dummy.next;

}
ListNode* listSort(ListNode* head){
    if(!head||!(head->next)) return head;//空或仅有一个元素直接返回
    ListNode *pre,*fast,*slow;
    fast=slow=head;
    while(fast&&fast->next){//快慢指针分割
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    pre->next=nullptr;
    ListNode *left=listSort(head);
    ListNode *right=listSort(slow);
    return merge(left,right);
}
void printList(ListNode *head){
    ListNode *curr=head;
    while(curr){
        cout<<curr->val<<"\t";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
   ListNode *head=new ListNode(3);
   //head->val=3;
   ListNode *node1=new ListNode(2);
   //node1->val=2;
   ListNode *node2=new ListNode(4);
   //node2->val=4;
   ListNode *node3=new ListNode(1);
   //node3->val=1;
   head->next=node1;
   node1->next=node2;
   node2->next=node3;
   node3->next=nullptr;
   head=listSort(head);
   printList(head);
   return 0;

}