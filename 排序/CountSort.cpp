#include<iostream>
#include<vector>
using namespace std;
//计数排序，根据
void CountSort(vector<int>& record,int max){
    vector<int> count(max+1,0);//创建count数组,统计对应0~max共max+1个数出现的次数
    for(int v:record){
        count[v]++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];//此时每个count[i]等于i最后一个i所在的位置+1，也等于<=i的元素的个数
    }
    vector<int> B(record.size());
    for(int i=0;i<int(record.size());i++){
        B[i]=record[i];
    }
    for(int i=record.size()-1;i>=0;i--){
        record[--count[B[i]]]=B[i];
    }
}

void printArr(vector<int>& record){
    for(int i:record){
        cout<<i<<"\t";
    }
    cout<<endl;
}
int main(){
    vector<int> record={9,4,4,6,7,0,2,5};
    CountSort(record,9);
    printArr(record);
}