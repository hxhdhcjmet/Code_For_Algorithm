#include<iostream>
#include<vector>
#include<list>
using namespace std;
struct Node{//创建节点
    int key;
    int next;
};
struct StaticQueue{
    int head;
    int tail;
};
int getMaxDigital(const vector<int>& record){
    int biggest=0;
    for(int v:record){
        if(v>biggest){
            biggest=v;
        }
    }
    //首先获得最大数，最大数得最大位数
    int digits=0;
    while(biggest>0){
        biggest/=10;
        digits++;
    }
    return digits;

}
int getDigit(int num,int d){//获得num的第d位数字,0代表个位对应10^0
    int division=1;
    while(d>0){
        d--;
        division*=10;
    }
    return (num/division)%10;
}
void RadixSort(vector<int>& record){
    int n=record.size();
    if(n<=1) return;
    vector<Node> nodes(n);
    for(int i=0;i<n;i++){//初始化链表,每个值对应record对应位置的值，下一个指向原数组中的下一个
        nodes[i].key=record[i];
        nodes[i].next=i+1;
    }
    nodes[n-1].next=-1;//最后一个的下一个定义为-1
    int maxDigital=getMaxDigital(record);//获得需要遍历的趟数;
    int head=0;
    vector<int> bucketHead(10,-1),bucketTail(10,-1);//初始化桶,首尾都为-1,
    for(int d=0;d<maxDigital;d++){//分配
        int curr=head;
        while(curr!=-1){
            int digit=getDigit(nodes[curr].key,d);//获得当前数的第d位数字
            if(bucketHead[digit]==-1){//对应位置的桶内还没有东西
                bucketHead[digit]=curr;
            }else{
                nodes[bucketTail[digit]].next=curr;//已经有了就把对应桶中最后一个的下一个改为curr
            }
            bucketTail[digit]=curr;
            curr=nodes[curr].next;
        }
              //collect过程
            head=-1;
            int last=-1;
            for(int i=0;i<10;i++){
                if(bucketHead[i]!=-1){
                    if(head==-1){//首次collect
                        head=bucketHead[i];
                    }else{
                        nodes[last].next=bucketHead[i];
                    }
                    last=bucketTail[i];
                    bucketHead[i]=bucketTail[i]=-1;//清空桶
                }
            }
            nodes[last].next=-1;//最后新链表末尾指向-1
    }

         int curr=head;
        for(int i=0;i<n;i++){ 
            record[i]=nodes[curr].key;
            curr=nodes[curr].next;
        }
}
void printArr(vector<int>& record){
    for(int v:record){
        cout<<v<<"\t";
    }
    cout<<endl;
}
int main(){
    vector<int> record={23,55,9,1,789,34};
    RadixSort(record);
    printArr(record);
    return 0;
}