#include<iostream>
#include<vector>
using namespace std;
const int THRESHOLD=28;//设定阈值,提高排序算法速度
void merge(vector<int>& record,vector<int>& tempArr,int left,int right,int middle){//合并函数
    //先将数组暂存在tempArr中
    for(int i=left;i<=right;i++){
        tempArr[i]=record[i];
    }
    //合并，从小到大顺序
    int index1=left,index2=middle+1;
    int i=left;
    while(index1<=middle&&index2<=right){//合并时左边右边都不能越界
        if(tempArr[index1]<=tempArr[index2]){//为了保证稳定性,用<=
            record[i++]=tempArr[index1++];
        }else{
            record[i++]=tempArr[index2++];
        }
    }
    while(index1<=middle){
        record[i++]=tempArr[index1++];
    }
    while(index2<=right){
        record[i++]=tempArr[index2++];
    }//两个循环扫尾,事实上这两个循环只会有一个进行
}
void mergeSort(vector<int>& record,vector<int>&tempArr,int left,int right){
    int middle;
    if(left<right){//只有满足左不大于右才进行
        middle=(left+right)/2;
        mergeSort(record,tempArr,left,middle);//递归左边
        mergeSort(record,tempArr,middle+1,right);//递归右边
        merge(record,tempArr,left,right,middle);//合并
    }
}

//一下为优化后的归并排序
void insertSort(vector<int>& record){
    int n=record.size();
    for(int i=1;i<n;i++){
        int temp=record[i];
        int j=i;
        while(j>0&&temp<record[j-1]){
            record[j]=record[j-1];
            j--;
        }
        record[j]=temp;
    }
}
void modMerge(vector<int>& record,vector<int>& tempArr,int left,int right,int middle){
    for(int i=left;i<=middle;i++){
        tempArr[i]=record[i];//record里的内容放到tempArr中
    }
    for(int i=middle+1,j=right;i<=right;i++,j--){
        tempArr[i]=record[j];
        
    }//优化关键在于右边逆序放
    int index1,index2,k;
    for(index1=left,index2=right,k=left;k<=right;k++){
        if(tempArr[index1]<=tempArr[index2]){
            record[k]=tempArr[index1++];
        }else{
            record[k]=tempArr[index2--];
        }
    }

}
void modMergeSort(vector<int>& record,vector<int>& tempArr,int left,int right){
    int middle;
    if(right-left+1>THRESHOLD){
        middle=(left+right)/2;
        modMergeSort(record,tempArr,left,middle);//递归左右+合并
        modMergeSort(record,tempArr,middle+1,right);
        modMerge(record,tempArr,left,right,middle);
    }
    else{
        insertSort(record);
    }

}
void printArr(vector<int>& record){
    for(int i:record){
        cout<<i<<"\t";
    }
    cout<<endl;
}
int main(){
    vector<int> record={2,3,1,0,6,5,88,9,15,102,500,1};
    vector<int> temp(record.size());
    //mergeSort(record,temp,0,record.size()-1);
    modMergeSort(record,temp,0,record.size()-1);
    printArr(record);
    return 0;
}