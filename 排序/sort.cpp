#include<iostream>
#include<vector>
using namespace std;
void insertSort(vector<int>& test){//插入排序
    int n=test.size();
    for(int i=1;i<n;i++){
        int j=i-1;
        while(j>=0&&test[j]>test[j+1]){
            swap(test[j],test[j+1]);
            j--;
        }
    }
}
void printResult(vector<int> test){
    for(auto it=test.begin();it<test.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
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
int main(){
    vector<int> example={3,2,6,7,1,8,9};
    bubbleSort(example);
    printResult(example);
    return 0;
}