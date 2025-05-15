#include<iostream>
#include<vector>
#include<random>
using namespace std;
const int len=20;//定义向量大小为1000
class GetRecord{
    public:
    vector<int> record;
    GetRecord(){
        record.resize(len,0);
    }
    void positiveOrder(){
        for(int i=0;i<len;i++){//获得正序
            record[i]=i;
        }
    }
    void reserveOrder(){//获得逆序
        for(int i=0;i<len;i++){
            record[i]=len-i-1;
        }
    }
    void randomOrder(){
        srand(time(0));
        for(int i=0;i<len;i++){
            record[i]=rand()%1000;//范围为0~999
        }
        
    }
    void randomOrderbett(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0,len-1);//均匀整数分布
        //normal_distribution 正态分布
        for(int& arr:record){
            arr=dis(gen);
        }
    }
    void printRecord(){
        for(auto it=record.begin();it<record.end();it++){
            cout<<*it<<"\t";
        }
        cout<<endl;
    }

};
/*void insertSort(vector<int>& test){//插入排序
    int n=test.size();
    for(int i=1;i<n;i++){
        int j=i-1;
        while(j>=0&&test[j]>test[j+1]){
            swap(test[j],test[j+1]);
            j--;
        }
    }
}*/
void insertSort(vector<int>& record){//插入排序
    int n=record.size();
    for(int i=1;i<n;i++){
        int key=record[i];
        int j=i-1;
        while(j>=0&&record[j]>key){
            record[j+1]=record[j];
            j--;
        }
        record[j+1]=key;
    }
}

void chooseSort(vector<int>& test){//选择排序
    int n=test.size();
    for(int i=0;i<n;i++){
        int smallest=i;
        for(int j=i;j<n;j++){
            if(test[smallest]>test[j]){
                smallest=j;
            }
        }
        swap(test[i],test[smallest]);
    }
}
void bubbleSort(vector<int>& test){
    int n=test.size();
    bool isSwap;
    for(int i=0;i<n-1;i++){
        isSwap=false;
        for(int j=0;j<n-i-1;j++){
            if(test[j]>test[j+1]){
                swap(test[j],test[j+1]);//后面一个更小就交换
                isSwap=true;//确实交换过就设置为true
            }
        }
        if(!isSwap) break;
    }
}
void printresult(vector<int>& record){
    int n=record.size();
    for(int i=0;i<n;i++){
        cout<<record[i]<<"\t";
    }
    cout<<endl;
}
int main(){
    GetRecord test;
    test.randomOrder();
    insertSort(test.record);
    printresult(test.record);
    return 0;
}